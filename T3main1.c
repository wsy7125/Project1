#include <stdio.h>

#include "Task3.h"

int main( void )

{
    double time=0.0;

    Node *head;
    head = makeNode( 0.0,0.0,0 );

    growTree( head );

    growTree( head );

    growTree( head );
    setZero( head );
    setFlag( head,time );
    
    addOrRemove( head );
    writeTree( head );
    destroyTree( head );



}
