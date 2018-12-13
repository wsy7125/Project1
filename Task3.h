struct qnode {
  int flag;
  int level;  //declare its level
  double xy[2]; //declare an array to store its bottom-left coordinates
  struct qnode *child[4]; //declare an array to store the pointers to its four children
}; //Define a structure variable to store the information about a node
typedef struct qnode Node; //Use "Node" to represent "struct qnode"


void removeChildren( Node *parent );
Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void growTree( Node *node );
double nodeValue( Node *node, double time );
double value( double x, double y, double time );
void setFlag( Node *node,double time );
void addOrRemove( Node *node,int add_number,int remove_number );
