#include "biblioteca.h"

/////////////////////////////////////
// Rotates around the current node 
int LeftRotate(struct Node *node)  // =1 if rotate works,=0 otherwise 
	{  struct Node *nd;  char* data;
	if(node==0 || node->Right==0) { return 0; }	// No Right Node!!

	nd=node->Right; node->Right=nd->Right;  // Move Node
	nd->Right=nd->Left; nd->Left=node->Left;
	node->Left=nd;

	data=node->Data;  node->Data=nd->Data; nd->Data=data;
	return 1;
	}


/////////////////////////////////////
// Rotate around current node
int RightRotate(struct Node *node) // =1 if rotate works, =0 otherwise
	{  struct Node *nd;  char* data;
	if(node==0 || node->Left==0) { return 0; }	

	nd=node->Left; node->Left=nd->Left;
	nd->Left=nd->Right; nd->Right=node->Right;
	node->Right=nd;

	data=node->Data; node->Data=nd->Data;  nd->Data=data;
	return 1;
	}



//////////////////////////////////////
void DSWBalancingAlgorithm(struct Node *root)
	{  struct Node *p;  int nodecount; int i;
	///////////// Create Linear Back Bone ///////////////////
	
	for(p=root,nodecount=0;p!=0;p=p->Right,++nodecount)
		{
		while(RightRotate(p)==1) { }
		}

	////////////  Perform Balancing ///////////////////////
	for(i=nodecount/2; i>0; i/=2 )
		{  int k;
		for(p=root,k=0;k<i;++k,p=p->Right)
			{ LeftRotate(p);  }
		}
	}


////////////////////////////////////////////////////////////
// The Following Code is used to Check how balanced is a tree
int Height(struct Node *root)    
	{
	if(root==0) { return 0; }
	return 1 + (max(Height(root->Left),Height(root->Right)));
	}


///////////////////////////////////////////////////////
// Following Function will Find the Sum of the Absolute diff in
// hight of every node.  The recursion below is terrible in running time!!!
int SumAbsDiff(struct Node *root) // =0 Means a perfect balanced tree
	{
	if(root==0) { return 0; }
	return abs(Height(root->Left)-Height(root->Right))
				+SumAbsDiff(root->Right)+SumAbsDiff(root->Left);
	}


/////////////////////////////////////
int InsertValue(struct Node **root,char* value)// =1 on success, =0 on fail
	{  struct Node *p,*nw;
	if((nw=(struct Node *)malloc(sizeof(struct Node)))==0) { return 0; }

	nw->Data=value; nw->Left=nw->Right=0;	
	nw->DSWrecorrencia = 0;

	if(*root==0) { (*root)=nw;  return 1; }

	for(p=*root; ; )
		{
		if(strcmp(value, p->Data)<0)
			{
			if(p->Left==0) { p->Left=nw; return 1; }
			p=p->Left;
			}
		else if(strcmp(value, p->Data)>0)
			{
			if(p->Right==0) { p->Right=nw; return 1; }
			p=p->Right;
			}
		else // We are trying to insert a value that exists in Strict BST
			{
			printf("Inserting Identical value into tree\n"); 
			nw->DSWrecorrencia = nw->DSWrecorrencia + 1;
			free(nw); return 0; 
			}
		}
	}


////////////////////////////////////////
void PrintTree(struct Node *root)
	{  // Perform Inorder Traversal of tree
	if(root==0) { return; }
	PrintTree(root->Left);
	printf("%s ",root->Data);
	printf(" - Recorrencia: %d",root->DSWrecorrencia);
	PrintTree(root->Right);
	}


////////////////////////////////////////
void DeleteTree(struct Node *root)
	{
	if(root==0) { return; }
	DeleteTree(root->Left);  DeleteTree(root->Right);
	free(root);	
	}



//////////////////////////////////////

/*
int main(void)
	{  struct Node *root=0;  int i;
	InsertValue(&root,"Son");
	InsertValue(&root,"of");
	InsertValue(&root,"a");
	InsertValue(&root,"bitch");
	InsertValue(&root,"bitc2");
	InsertValue(&root,"bitch3");
	InsertValue(&root,"bitchdfs");
	InsertValue(&root,"bitsdfdsch");
	InsertValue(&root,"dsfsdfbitch");
	InsertValue(&root,"aabitch");
	InsertValue(&root,"asdafbitch");

	printf("Before Balancing : %d\n",SumAbsDiff(root));
	DSWBalancingAlgorithm(root);
	printf("After Balancing  : %d\n",SumAbsDiff(root));
	
	DeleteTree(root); root=0; return 0;
	}
	
*/
