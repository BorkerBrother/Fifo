#include "stdio.h"
#include "stdlib.h"


typedef struct Knoten
{
    int wert;
    struct Knoten *links, *rechts;

} Knoten;


// Diese Funktion initialisiert einen Binärbaumknoten mit einem gegebenen Wert.
// Sie erzeugt einen neuen Knoten und setzt dessen Wert auf den übergebenen Wert.
void init(Knoten** baumKnoten, int wert)
{
    Knoten* tmpinit = malloc(sizeof (baumKnoten));
    tmpinit->links = NULL;
    tmpinit->rechts = NULL;
    tmpinit->wert = wert;

    *baumKnoten = tmpinit;
}

// Diese Funktion fügt einen neuen Wert in den Binärbaum ein.
// Sie vergleicht den neuen Wert mit dem Wert im aktuellen Knoten und fügt ihn entsprechend ein.
// Wenn der neue Wert kleiner ist als der aktuelle Wert, wird er im linken Teilbaum eingefügt.
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
