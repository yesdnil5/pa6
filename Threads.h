#include "BookOrder.h"

void orders(Node *client, char* book);
void scanOrders(FILE *orderFile, Node clients[]);
void produceThread(char* cat, FILE *orderFile, Node clients[]);
void createCategories(FILE *catFile, char* catString);
