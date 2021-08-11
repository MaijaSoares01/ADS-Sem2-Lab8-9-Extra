/****************************************************************/
/*  This is a sample program to demonstrate the functioning     */
/*  of a simple BST of integers.							    */
/*  The actions carried out are as follows :				    */
/*		1. 5 integers are input by the user into the tree       *
/*		2. All 5 values are displayed using postorder traversal */ 
/*		3. The user is asked to select a node to delete a node  */
/*			from the tree.									    */
/*	                                                            */
/*                                                              */
/****************************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define bool int
#define true 1
#define false (!true)

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
void displayInOrder (struct BinarySearchTreeNode *);
bool isEmpty();
void addElement (struct data) ;
struct BinarySearchTreeNode *replacement (struct BinarySearchTreeNode *); 
void removeElement (struct data);
void removeMin();


struct BinarySearchTreeNode *root = NULL;
int treeCounter = 0;

/************MAIN FUNCTION**********************/

int main()
{
	struct data anElement;
	bool finished = false;
	int index;

	// INPUT THE 5 VALUES 
	printf("\nStep 1 - Enter 5 integers into the BST \n ");
	for (index=0; index < 5; index++) {
		printf("Enter value %d: ", index + 1);
		scanf("%d", &anElement.value);
		addElement(anElement);
	}
	
	// DISPLAY THE CONTENTS OF THE TREE
	printf("\nStep 2 - Display the contents of the tree using an inorder traversal \n");
	displayInOrder(root);


	// DELETE A NODE FROM THE TREE
	printf("\n\nStep 3 - Delete a node from the tree \n ");
 
  if (isEmpty())
	  printf("There are no nodes left in the tree to delete\n");
  else {	
		printf("\nEnter value to delete : ");
		scanf("%d", &anElement.value);
		if (anElement.value != 0) {
			removeElement(anElement);
			displayInOrder(root);
		}//end if
  }//end else
  
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

/******************************************************************/
/*                                                                */
/* Display the contents of the tree using postorder traversal     */
/*                                                                */
/******************************************************************/  

void displayInOrder (struct BinarySearchTreeNode *tree)
{
	if (tree != NULL)
	{
		displayInOrder(tree->left);
	
		printf(" %d ", tree->element.value);
		displayInOrder(tree->right);
	
	
		
	}
}


/*****************************************/
/* Add a new element with a data part as */
/* specific by "element" into the tree   */
/*****************************************/

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



//===============================================================   
//  Removes the first element that matches the specified target
   //  element from the binary search tree and returns the address of 
   //  it.  Display an error message if the specified target
   //  element is not found in the binary search tree.
   //===============================================================   
void removeElement (struct data targetElement)
   { 
		struct BinarySearchTreeNode *current, *parent;
		bool found = false;

      if (!isEmpty())

         if (targetElement.value == root->element.value)
         {
            root = replacement (root);
            treeCounter--;
         } //if
        else 
        {
            current = parent = root;
            
            if (targetElement.value < root->element.value)
				current = root->left;
            else
               current = root->right;

            while (current != NULL && !found) 
            {
               if (targetElement.value == current->element.value) 
               {
                  found = true;
                  treeCounter--;
          
                  if (current == parent->left) //is target element to left?
                  {
                     parent->left = replacement (current);
                  }
                  else //or right?
                  {
                     parent->right = replacement (current);
                  }
               } //if
              else 
              {
                  parent = current;
         
                  if (targetElement.value < current->element.value)
                     current = current->left;
                  else
                     current = current->right;
               } //else
            } //while
            if (!found)
               printf("No such element found\n");
			else
				printf("%d has been deleted\n", targetElement.value);
         } //else

      

   }  // method removeElement

   struct BinarySearchTreeNode *replacement (struct BinarySearchTreeNode *node) 
   {
      struct BinarySearchTreeNode *current, *parent, *result; 
	  
	  result = NULL;

      if ((node->left == NULL)&&(node->right==NULL))
            result = NULL;
      else if ((node->left != NULL)&&(node->right==NULL))
            result = node->left;
      else if ((node->left == NULL)&&(node->right != NULL))
            result = node->right;
      else
      {
            current = node->right;
            parent = node;

            while (current->left != NULL) 
            {
               parent = current;
               current = current->left;
            }//while

            if (node->right == current)
               current->left = node->left;
            else
            {
               parent->left = current->right;
               current->right = node->right; //allow placement node point to the right node of the node to be deleted
               current->left = node->left;
            }
            result = current;
      }//else
      return result;


   }  // method replacement

 


  
