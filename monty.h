#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>

#define STACK_MAX_SIZE 100

typedef struct {
  int data[STACK_MAX_SIZE];
  int top;
} Stack;

extern Stack stack;

void push(int value);
int pop(void);
void pall(void);

#endif /* MONTY_H */
