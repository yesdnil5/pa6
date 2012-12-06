
struct ClientPTR{
    char *name;
    int id;
    float price;
};

typedef struct ClientPTR Client;

void destroyClient(Client clients[], int num);
int numLines(FILE *clientFile);
void createClients(FILE *cf, Client clients[]);
int main(int argc, char** argv);
