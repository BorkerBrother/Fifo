#include "stdio.h"
#include "stdlib.h"


typedef struct Knoten
{
    int wert;
    struct Knoten *links, *rechts;

} Knoten;


void init(Knoten** baumKnoten, int wert)
{
    Knoten* tmpinit = malloc(sizeof (baumKnoten));
    tmpinit->links = NULL;
    tmpinit->rechts = NULL;
    tmpinit->wert = wert;

    *baumKnoten = tmpinit;
}

void push(Knoten* knoten, int neuerWert)
{
    if (neuerWert < knoten->wert) {
        if (knoten->links == NULL) {
            Knoten* tmp_neu;
            init(&tmp_neu, neuerWert);
            knoten->links = tmp_neu;
        } else {
            push(knoten->links, neuerWert);
        }
    }
}



int main() {


    Knoten* baum;
    init(&baum,100);

    push(&baum,3);

    return 0;
};
