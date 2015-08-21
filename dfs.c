#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
/* a simple graph (binary tree)
         (0,    3)   <– root node
          /     \
      (1, 2)    (1,4)
       /  \     /   \
   (2,1) (2,2) (2,3) (2,5)
*/
typedef struct Graph {
   struct GraphNode* root;
} Graph;
struct GraphNode initNode(int _h, int _w) {
   struct GraphNode node;
   node.pvalue.h = _h;
   node.pvalue.w = _w;
   node.left = NULL;
   node.right = NULL;
   return node;
}
int main() {
   struct Graph g;
   struct GraphNode currentNode;
   /*read in the graph from top to bottom*/
   g.root = (GraphNode*) malloc(sizeof(GraphNode));
   *g.root = initNode(0, 3);
   //level 2 nodes
   g.root->left = (GraphNode*) malloc(sizeof(GraphNode));
   *g.root->left = initNode(1, 2);
   g.root->right = (GraphNode*) malloc(sizeof(GraphNode));
   *g.root->right = initNode(1, 4);
   //level 3 nodes
   (*g.root->left).left = (GraphNode*) malloc(sizeof(GraphNode));
   *(*g.root->left).left = initNode(2, 1);
   (*g.root->left).right = (GraphNode*) malloc(sizeof(GraphNode));
   *(*g.root->left).right = initNode(2, 2);
   (*g.root->right).left = (GraphNode*) malloc(sizeof(GraphNode));
   *(*g.root->right).left = initNode(2, 3);
   (*g.root->right).right = (GraphNode*) malloc(sizeof(GraphNode));
   *(*g.root->right).right = initNode(2, 5);
   /*DFS traversal*/
   Stack s;
   initStack(&s);
   push(&s, *g.root);
   while (!ifEmpty(&s)) {
       currentNode = top(&s);
        pop(&s);
        //mark as visited, here we simply print the graph node value out
       printf("(%d, %d)\n", currentNode.pvalue.h, currentNode.pvalue.w);
        //at most two children, left and right. As the binary tree is acyclic,
        // both nodes should not be visited yet, for cyclic graphs, 
        //one need additional methods to check if the nodes is visited or not before push
       if (currentNode.left != NULL) {
           push(&s, *currentNode.left);
       } 
       if (currentNode.right != NULL) {
           push(&s, *currentNode.right);
        } 
   }
   return 0;
}