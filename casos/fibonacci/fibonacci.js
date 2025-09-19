function fibrec(n) {
  if (n <= 1) return n;
  return fibrec(n - 1) + fibrec(n - 2);
}
console.log(fibrec(40));
