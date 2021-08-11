/****************************************************************
  This is a sample program to demonstrate the functioning     
  of a simple BST of integers.							    
   The actions carried out are as follows : 		
   1. 5 integers are input by the user into the tree
   2. All 5 values are displayed using inorder traversal 	                                   						                                                            
***************************************************************/

#define _CRT_SECURE_NO_WARNINGS
#define bool int
#define false 0
#define true (!false)
#include <stdio.h>
#include <stdlib.h>


struct data {
	int value;
};

struct BinarySearchTreeNode 
{
	struct data element;
	struct BinarySearchTreeNode *left;
	struct BinarySearchTreeNode *right;
};


//Function Prototypes
struct BinarySearchTreeNode *createNode (struct data);
void inorder (struct BinarySearchTreeNode *);
bool isEmpty();
void addElement (struct data) ;


//Global Variables
struct BinarySearchTreeNode *root = NULL;
int treeCounter = 0;

/************MAIN FUNCTION**********************/

int main()
{
	struct data anElement;
	bool finished = false;

	// INPUT THE 5 VALUES 
	printf("\nStep 1 - Enter 5 integers into the BST \n ");
	int index;
	for (index=0; index < 5; index++) {
		printf("Enter value %d: ", index + 1);
		scanf("%d", &anElement.value);
		addElement(anElement);
	}
	
	// DISPLAY THE CONTENTS OF THE TREE
	printf("\nStep 2 - Display the contents of the tree using an inorder traversal \n");
	inorder(root);


 
getchar(); getchar();
printf("\n");
}//method main


// Create a node in memory and return its address
  struct BinarySearchTreeNode *createNode (struct data anElement) {
	struct BinarySearchTreeNode *pointer;
   
	pointer = (struct BinarySearchTreeNode *)malloc(sizeof (struct BinarySearchTreeNode));
   	pointer->element = anElement;
	pointer->left = NULL;
	pointer->right = NULL;
	
	if (isEmpty()) //need to assign the root pointer
		root = pointer;
	//	treeCounter++;

	return pointer;
}


// check to see if the tree is empty
  bool isEmpty() {
	  return (treeCounter==0);
  }

/*****************************************************************                                                      
 Display the contents of the tree using an inorder traversal  
 This will display the tree values in sorted order                                                                     
*****************************************************************/  

void inorder (struct BinarySearchTreeNode *tree)
{
	if (tree != NULL)
	{
		inorder(tree->left);
		printf(" %d ", tree->element.value);
		inorder(tree->right);
	
	}
}


/****************************************
 Add a new element with a data part as 
 specific by "element" into the tree   
*****************************************/

void addElement (struct data anElement) 
   {
	  struct BinarySearchTreeNode *pointer, *current;
      pointer = createNode (anElement);

      if (isEmpty())
         root = pointer;
      else 
      {
         current = root;
		 while (current != NULL) 
         {
			 if (anElement.value < current->element.value) {

               if (current->left == NULL) 
               {
                  current-> left = pointer;
				  current = NULL;
               } //end if
               else
                  current = current->left;
			 } //end if
			 else {
               if (current->right == NULL) 
               {
                  current->right = pointer;
				  current = NULL;
               } //end if
               else
                  current = current->right;
			 } //end else
         }//end while
      }//end else

      treeCounter++;

   }  // method addElement




