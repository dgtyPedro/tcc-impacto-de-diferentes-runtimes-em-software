./quickjs/fibotime fibotime.js

docker buildx build --platform linux/arm64 -t fibonacci-bench .
docker run -it fibonacci-bench

1 git clone https://github.com/bellard/quickjs.git
2 cd quickjs/
3 make -j$(sysctl -n hw.ncpu)
4 ./qjs -v
6 cd ../
7 cp ./fibotime/functions.c ./quickjs/functions.c
8 cd quickjs/
9 gcc -std=c11 -O2 -I. -o fibotime functions.c libquickjs.a -lm -pthread

hyperfine './native/quickjs/fibotime ./native/fibotime.js' 'node fibonacci.js' 'deno fibonacci.js' 'bun fibonacci.js' --warmup 3 --runs 20 -N
