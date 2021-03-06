#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Task3.h"
struct qnode {
  int flag;
  int level;  //declare its level
  double xy[2]; //declare an array to store its bottom-left coordinates
  struct qnode *child[4]; //declare an array to store the pointers to its four children
}; //Define a structure variable to store the information about a node
typedef struct qnode Node; //Use "Node" to represent "struct qnode"
void removeChildren( Node *parent )
{
    int i;
    for ( i=0; i<4; ++i )
        free( parent->child[i] );
    for ( i=0; i<4; ++i )
        parent->child[i]=NULL;

    return;

}

Node *makeNode( double x, double y, int level )
{
    int i;

    Node *node = (Node *)malloc(sizeof(Node));

    node->level = level;

    node->xy[0] = x;
    node->xy[1] = y;

    for( i=0;i<4;++i )
        node->child[i] = NULL;

    return node;
}

void makeChildren( Node *parent )
{
    double x = parent->xy[0];
    double y = parent->xy[1];

    int level = parent->level;

    double hChild = pow(2.0,-(level+1));

    parent->child[0] = makeNode( x,y, level+1 );
    parent->child[1] = makeNode( x+hChild,y, level+1 );
    parent->child[2] = makeNode( x+hChild,y+hChild, level+1 );
    parent->child[3] = makeNode( x,y+hChild, level+1 );

    return;
}

void growTree( Node *node )
{
    int i;

    if( node->child[0] == NULL )
        makeChildren( node );
    else
    {
        for ( i=0; i<4; ++i )
        {
            growTree( node->child[i] );
        }

    }
    return;
}
double nodeValue( Node *node, double time )
{
    int level = node->level;
    double x = node->xy[0];
    double y = node->xy[1];

    double h = pow(2.0,-level);

    return( value( x+0.5*h, y+0.5*h, time ) );
}

// Data function

double value( double x, double y, double time )
{
    return( 2.0*exp(-8.0*(x-time)*(x-time)) - 1.0 ) ;
}

void setFlag( Node *node,double time )
{
    int i;

    if( node->child[0] == NULL )
    {
        if( nodeValue( node, time )>0.5 )
            node->flag=1;
        else if( nodeValue( node, time )<-0.5 )
            node->flag=-1;
        else
            node->flag=0;

    }
    else
    {
        for ( i=0; i<4; ++i )
        {
            setFlag( node->child[i],time );
        }
        node->flag=0;

    }
    return;
}

void addOrRemove( Node *node,int add_number,int remove_number )
{
    int i;
    int check_children;
    if( node->child[0] == NULL )
    {
        if( node->flag==1 )
            makeChildren( node );
            add_number+=4;
        if( node->flag==-1 )
            check_children++;

    }
    else
    {
        check_children=0;
        for ( i=0; i<4; ++i )
            addOrRemove( node->child[i],add_number,remove_number );
        if( check_children==4 )
            removeChildren( node );
            remove_number+=4;
    }
    printf( "%i",add_number );
    printf( "%i",remove_number );
    return;

}
void writeTree( Node *head ) {

  FILE *fp = fopen("quad.out","w");

  writeNode(fp,head);

  fclose(fp);

  return;
}

// recursively visit the leaf nodes

void writeNode( FILE *fp, Node *node ) {

  int i;

  if( node->child[0] == NULL )
    printOut( fp, node );
  else {
    for ( i=0; i<4; ++i ) {
      writeNode( fp, node->child[i] );
    }
  }
  return;
}

// write out the (x,y) corners of the node

void printOut( FILE *fp, Node *node ) {
  double x = node->xy[0];
  double y = node->xy[1];
  int level = node->level;
  double h = pow(2.0,-level);

  fprintf(fp, " %g %g\n",x,y);
  fprintf(fp, " %g %g\n",x+h,y);
  fprintf(fp, " %g %g\n",x+h,y+h);
  fprintf(fp, " %g %g\n",x,y+h);
  fprintf(fp, " %g %g\n\n",x,y);

  return;
}
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
    writeTree( head )


}
