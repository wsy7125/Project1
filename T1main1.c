#include <stdio.h>
#include "Task1.h"

int main( void )
{
    Node *head;
    head = makeNode( 0.0,0.0,0 );
    growTree( head );
    growTree( head );
    destroyTree( head );

}
