static i = -1;
enum x{sat,sun,mon};
struct node *create(int data){
struct node *ptr = NULL;
ptr = (struct node*)malloc(sizeof(struct node));
if(ptr){

    ptr->data = data;
    ptr->pnex = NULL;
}
return ptr;
}
