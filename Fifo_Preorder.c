#include "stdio.h"
#include "malloc.h"

// Binärbaum datensatz mit zwei zeigern pro Kopf
// Präorder
// Traversierung = Wurzel -> Links -> Rechts

typedef struct Knoten
{
    int wert;
    struct Knoten *links, *rechts;

} Knoten;


void linit(Knoten** baumKnoten, int wert)
{
    Knoten* tmpinit;
    tmpinit = malloc(sizeof (baumKnoten));
    tmpinit->links =  malloc(sizeof (baumKnoten));
    tmpinit->links = NULL;
    tmpinit->rechts = malloc(sizeof (baumKnoten));
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
        tmp->links = tmp_neu;
    }
    else
    {
        tmp->rechts = tmp_neu;
    }

}


void print(Knoten** Baumknoten)
{
    Knoten* tmp;

    tmp = *Baumknoten;

    if (tmp->links == NULL ||  tmp->rechts == NULL || tmp->wert != NULL)
    {
        printf(" -> %d" , tmp->wert);
        tmp = tmp->rechts;

    }

    else
    {
        tmp->rechts = tmp;
    }

    if ( tmp->wert != NULL)
    {
        print(&tmp);
    }

}

int main() {

    Knoten* baum;
    linit(&baum,100);

    int test = 150;

    einfügen(&baum,test);

    int test2 = 125;

    einfügen(&baum,test2);

    print(&baum);

    return 0;
};
