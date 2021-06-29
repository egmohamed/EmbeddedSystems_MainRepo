

 struct node{
 int data;
 struct node *pnext;
 struct node *pprev;
 };
 struct node *head;
struct node *tail;
struct node* createnode(int data);
 int enque(int data);
