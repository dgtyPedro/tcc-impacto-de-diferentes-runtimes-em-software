Deno.serve({ port: 3000 }, (req) => {
  if (req.method === "GET" && new URL(req.url).pathname === "/") {
    return new Response("Hello from Deno native HTTP!\n", { status: 200 });
  }
  return new Response("Not found\n", { status: 404 });
});

console.log("Deno HTTP server running at http://localhost:3000/");
