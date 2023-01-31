typedef struct node
{
    int data;
    struct node *next;
}node_t;

int is_stack_empty(void);
void push(int value);
int pop(void);
void display_stack_elements(void);
int top_element(void);
int stack_count(void);
