Bun.serve({
  port: 3000,
  fetch(req) {
    if (req.method === "GET" && new URL(req.url).pathname === "/") {
      return new Response("Hello from Bun native HTTP!\n", { status: 200 });
    }
    return new Response("Not found\n", { status: 404 });
  },
});

console.log("Bun HTTP server running at http://localhost:3000/");
