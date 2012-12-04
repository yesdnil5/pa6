
struct NodePTR{
    char* category;
    struct NodePTR *next;
};
typedef struct NodePTR Node;

Node* createCat(char* cat);
int main(int argc, char** argv);
