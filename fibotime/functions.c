// embed.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quickjs.h"

static uint64_t fib_recursive(uint32_t n) {
    if (n <= 1) return n;
    return fib_recursive(n - 1) + fib_recursive(n - 2);
}

// JS binding for fib_recursive
static JSValue fibrec(JSContext *ctx, JSValueConst this_val,
                                      int argc, JSValueConst *argv) {
    int32_t n;

    if (argc < 1 || JS_ToInt32(ctx, &n, argv[0])) {
        return JS_ThrowTypeError(ctx, "Expected a number");
    }
    if (n < 0) {
        return JS_ThrowRangeError(ctx, "Expected a non-negative number");
    }

    uint64_t result = fib_recursive((uint32_t)n);
    printf("%llu\n",  (unsigned long long)result);

    return JS_NewInt64(ctx, result);
}

static char *read_file(const char *filename, size_t *plen) {
    FILE *f = fopen(filename, "rb");
    if (!f) return NULL;
    fseek(f, 0, SEEK_END);
    size_t len = ftell(f);
    fseek(f, 0, SEEK_SET);
    char *buf = malloc(len + 1);
    if (!buf) { fclose(f); return NULL; }
    if (fread(buf, 1, len, f) != len) { free(buf); fclose(f); return NULL; }
    buf[len] = '\0';
    fclose(f);
    if (plen) *plen = len;
    return buf;
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s script.js [args...]\n", argv[0]);
        return 1;
    }

    const char *filename = argv[1];
    size_t len;
    char *buf = read_file(filename, &len);
    if (!buf) { perror("read_file"); return 1; }

    JSRuntime *rt = JS_NewRuntime();
    JSContext *ctx = JS_NewContext(rt);

    JSValue global_obj = JS_GetGlobalObject(ctx);
    JS_SetPropertyStr(ctx, global_obj,
                      "fibrec",
                      JS_NewCFunction(ctx, fibrec, "fibrec", 1));
    JS_FreeValue(ctx, global_obj);

    JSValue val = JS_Eval(ctx, buf, len, filename, JS_EVAL_TYPE_GLOBAL);

    if (JS_IsException(val)) {
        JSValue exc = JS_GetException(ctx);
        const char *err = JS_ToCString(ctx, exc);
        fprintf(stderr, "Exception: %s\n", err);
        JS_FreeCString(ctx, err);
        JS_FreeValue(ctx, exc);
    }
    JS_FreeValue(ctx, val);
    free(buf);

    JS_FreeContext(ctx);
    JS_FreeRuntime(rt);
    return 0;
}
