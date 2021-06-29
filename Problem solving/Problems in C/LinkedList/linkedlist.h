
struct node{
int data;
struct node *pnex;
struct node *pprev;
};

struct node *head;
struct node *tail;
 struct node* createNode(int data);
int addNode(int data);
int insertData(int data,int loc);
