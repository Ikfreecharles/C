#include <stdio.h>
#include <stdbool.h>

struct employee {
  char *name;
  int age;
  bool is_paid;
};

struct employee *profile(char *a, int, bool);

int main(int argc, char *argv[])
{

  struct {
    int age;
    char alias[20];
    int sex;
    bool is_employed;
    bool is_paid;
  } employee1 = {24, "jacko", 1, true, true}, employee2 = {28, "cleaner", 0, true, true};

  printf("Age is: %d\n", employee1.age);
  printf("Alias is: %s\n", employee1.alias);
  printf("Employee 2 is paid? %d\n\n", employee2.is_paid);

  struct employee *annie_profile = profile("Annie", 20, true);
  printf("Profile 1 name is %s\n", annie_profile->name);
  return 0;
}

struct employee *profile(char *name, int age, bool is_paid) {
  return &(struct employee) {.name=name, age, is_paid};
}