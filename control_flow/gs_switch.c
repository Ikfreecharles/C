#include <stdio.h>

int main(int argc, [[maybe_unused]] char* argv[argc+1]) {
switch (argc)
{
case 0:
  puts("This is zero");
  break;
case 1:
  puts("This is one");
  break;
default:
  puts("This is the default");
  break;
}
}