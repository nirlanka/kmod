#include <stdio.h>
#include <stdlib.h>
typedef struct Point {
       int h;
          int w;

} Point;
typedef struct GraphNode {
       struct Point pvalue;
          struct GraphNode* left;
             struct GraphNode* right;

} GraphNode;
typedef struct StackElement {
        struct GraphNode value;
           struct StackElement *up;
              struct StackElement *down;

} StackElement;
typedef struct Stack {
        struct StackElement* topP;
           struct StackElement* bottomP;

} Stack;
void initStack(struct Stack *s);
void push(struct Stack *s, struct GraphNode _value);
void pop(struct Stack *s);
struct GraphNode top(struct Stack *s);
int ifEmpty(struct Stack *s);
