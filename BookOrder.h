
struct ClientPTR{
    char *name;
    int id;
    float price;
    float total;
    struct ClientPTR *nextSucc;
    struct ClientPTR *nextFail;
};

typedef struct ClientPTR Node;

void destroyClient(Node clients[], int num);
int numLines(FILE *clientFile);
void createClients(FILE *cf, Node clients[]);
int main(int argc, char** argv);
