
struct qnode {
  int level;  //declare its level
  double xy[2]; //declare an array to store its bottom-left coordinates
  struct qnode *child[4]; //declare an array to store the pointers to its four children
}; //Define a structure variable to store the information about a node
typedef struct qnode Node; //Use "Node" to represent "struct qnode"

Node *makeNode( double x, double y, int level );
void makeChildren( Node *parent );
void growTree( Node *node );
void destroyTree( Node *node );
