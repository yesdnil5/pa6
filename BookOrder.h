
struct ClientPTR{
    char *name;
    int id;
    float price;
};

typedef struct ClientPTR Client;

int numLines(FILE *clientFile);
void createClients(FILE *cf, Client *clients[]);
int main(int argc, char** argv);
