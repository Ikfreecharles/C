swap:
  slli x6, x11, 2
  add x6, x10, x6
  lw x5, 0(x6)
  lw x7, 4(x6)
  sw x7, 0(x6)
  sw x5, 4(x6)
  jalr x0, 0(x1)