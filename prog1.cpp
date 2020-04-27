#include <bits/stdc++.h>
using namespace std;
 
int vertex,k,minval;
vector <int> visited; //A vector defined to keep track of the visited nodes.
/*Definition of tree nodes which store the name of the node and the singular weight as 1,
while also having 5 empty children.*/
struct node 
{
    int data;
    int weight;
    struct node *one;
    struct node *two;
    struct node *three;
    struct node *four;
    struct node *five;
};

//Initialisation of all nodes. 
struct node *newNode(int data, int w)
{
	struct node *node = new struct node;
	node->data = data;
  	node->weight= w+1;
  	node->one = NULL;
 	node->two = NULL;
 	node->three = NULL;
 	node->four = NULL;
 	node->five = NULL;
	return(node);
}

//Function to create the tree and add nodes to form the paths. 
void addNodes(struct node* root)
{
   int j;
   visited[(root->data)]+=1;
   visited[((root->data)+1)%vertex]+=1;
   visited[((root->data)-1 + vertex)%vertex]+=1;
   visited[((root->data)+k)%vertex]+=1;
   visited[((root->data)-k + vertex) %vertex]+=1;
   
   for(j=((root->data)+1)%vertex; j!=(root->data);j=(j + 1) % vertex)
   {
    	if(visited[j]==0)
      	{
         	root->one=newNode(j,(root->weight));
         	root->two=newNode((j-1 + vertex)%vertex,(root->weight));
         	root->three=newNode((j+1)%vertex,(root->weight));
         	root->four=newNode((j-k + vertex)%vertex,(root->weight));
         	root->five=newNode((j+k)%vertex,(root->weight));
         
         	addNodes(root->one);

          	visited[(root->one->data)]-=1;
          	visited[((root->one->data)+1)%vertex]-=1;
          	visited[((root->one->data)-1 + vertex)%vertex]-=1;
          	visited[((root->one->data)+k)%vertex]-=1;
          	visited[((root->one->data)-k + vertex) %vertex]-=1;

			addNodes(root->two);
         
          	visited[(root->two->data)]-=1;
          	visited[((root->two->data)+1)%vertex]-=1;
          	visited[((root->two->data)-1 + vertex)%vertex]-=1;
          	visited[((root->two->data)+k)%vertex]-=1;
          	visited[((root->two->data)-k + vertex) %vertex]-=1;

	        addNodes(root->three);
         
          	visited[(root->three->data)]-=1;
          	visited[((root->three->data)+1)%vertex]-=1;
          	visited[((root->three->data)-1 + vertex)%vertex]-=1;
          	visited[((root->three->data)+k)%vertex]-=1;
          	visited[((root->three->data)-k + vertex) %vertex]-=1; 

         	addNodes(root->four);
         
          	visited[(root->four->data)]-=1;
          	visited[((root->four->data)+1)%vertex]-=1;
          	visited[((root->four->data)-1 + vertex)%vertex]-=1;
          	visited[((root->four->data)+k)%vertex]-=1;
          	visited[((root->four->data)-k + vertex) %vertex]-=1;

         	addNodes(root->five);

          	visited[(root->five->data)]-=1;
          	visited[((root->five->data)+1)%vertex]-=1;
          	visited[((root->five->data)-1 + vertex)%vertex]-=1;
          	visited[((root->five->data)+k)%vertex]-=1;
          	visited[((root->five->data)-k + vertex) %vertex]-=1;
			break;
      }
	}
   	if(j==(root->data))
    	minval= std::min(minval,(root->weight));
} 

int main()
{
	cout<<"Enter n:";
  	cin>>vertex;
  	cout<<"Enter k:";
  	cin>>k;
	minval=INT_MAX;
  	visited.resize(vertex);
  	for(int i=0;i<vertex;i++)
    	visited.push_back(0);
  	struct node *root = newNode(0,0);
  	addNodes(root);
	cout<<"Domination number:"<<minval<<endl;
  	return 0;
}
