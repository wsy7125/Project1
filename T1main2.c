#include <stdio.h>
#include "Task1.h"

int main( void )
{
    Node *head;
    head = makeNode( 0.0,0.0,0 );
    growTree( *head );
    makeChildren( head->child[0] )
    destroyTree( *head );

}
