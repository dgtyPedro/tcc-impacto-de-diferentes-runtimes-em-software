./fibotime/fibotime fibotime.js

docker buildx build --platform linux/arm64 -t fibonacci-bench .
