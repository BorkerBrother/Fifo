
#include "stdio.h"
#include "stdlib.h"


typedef struct Knoten
{
    int wert;
    struct Knoten *links, *rechts;

} Knoten;


void linit(Knoten** baumKnoten, int wert)
{
    Knoten* tmpinit;
    tmpinit = static_cast<Knoten *>(malloc(sizeof(baumKnoten)));
    tmpinit->links = static_cast<Knoten *>(malloc(sizeof(baumKnoten)));
    tmpinit->links = NULL;
    tmpinit->rechts = static_cast<Knoten *>(malloc(sizeof(baumKnoten)));
    tmpinit->rechts = NULL;
    tmpinit->wert = wert;

    *baumKnoten = tmpinit;
}

void einfügen(Knoten** baumKnoten, int neuerWert)
{
    Knoten *tmp,*tmp_neu;
    *baumKnoten = tmp;
    linit(&tmp_neu, neuerWert);

    // Links kleiner als Wurzel
    if (tmp_neu->wert < tmp->wert)
    {
        *baumKnoten = tmp_neu;
    }

}

int main() {


    Knoten* baum;
    linit(&baum,100);

    einfügen(&baum,3);
    int test = 1;

    return 0;
};
