#include <stdio.h>

#include "Task3.h"

int main( void )

{
    int add_number=0;
    int remove_number=0;
    double time=0.0;

    Node *head;
    head = makeNode( 0.0,0.0,0 );

    growTree( head );

    growTree( head );

    growTree( head );

    setFlag( head,time );

    addOrRemove( head,add_number,remove_number );



}
