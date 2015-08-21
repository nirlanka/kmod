/**
a C stack implementation using linked list
*/
#include "stack.h"
/*initialize the stack*/
void initStack(struct Stack *s) {
   s->topP = NULL;
   s->bottomP = NULL;
}
/*add an element to the top of the stack*/
void push(struct Stack *s, struct GraphNode _value) {
   //allocate a new StackElement for _value
   StackElement *newElement;
   newElement = (StackElement*) malloc(sizeof(StackElement));
   newElement->value = _value;
   newElement->up = NULL;
   newElement->down = NULL;
   if (s->topP == NULL) {
        //first element
       s->topP = newElement;
        s->bottomP = newElement;
   } else {
        //push it to the top
        newElement->down = s->topP;
        s->topP = newElement;
   }
}
/*delete the top element from the stack*/
void pop(struct Stack *s) {
   StackElement *element;
   if (s->topP == NULL) {
        //empty stack
        return;
   } else {
        element = s->topP;
        s->topP = element->down;
        if (s->topP != NULL)
             s->topP->up = NULL;
        free(element);
   }
}
/*get the top value of the stack, but don't delete it*/
struct GraphNode top(struct Stack *s) {
   return s->topP->value;
}
/*check if the stack is empty*/
int ifEmpty(struct Stack *s) {
   return (s->topP == NULL ? 1:0);
}