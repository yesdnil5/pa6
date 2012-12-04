
struct NodePTR{
    char* category;
    struct NodePTR *next;
};
typedef struct NodePTR Node;

void destroyList(Node* ptr);
Node* createCat(char* cat);
int main(int argc, char** argv);
