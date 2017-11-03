//Kieta Appenah CS3D5A Assignment 3: Trees & Search 29/11/2016

#include <stdio.h>
#include <stdlib.h>

typedef struct Tree_Node Tree_Node;

struct Tree_Node
{
	char data;
	Tree_Node *left, *right;
};

void tree_insert(Tree_Node** root, char data)
{
	if (*root == NULL)//make new root
	{
		*root = (Tree_Node*)malloc(sizeof(Tree_Node));//allocate memory
		(*root)->data = data;
		(*root)->left = NULL;
		(*root)->right = NULL;
	}
	else  
	{
		if (data < (*root)->data)
		{
			tree_insert(&(*root)->left, data);//insert in the left sub tree
		}
		else
		{
			tree_insert(&(*root)->right, data);//insert in the right sub tree	
		}
	}
}
	

Tree_Node* tree_search(Tree_Node* root, char data)
{
	if(root == NULL)
        {
                return NULL;//character not found
        }
        else if(data > root->data)
        {
                return tree_search(root->right, data);//Search in the right sub tree
        }
        else if(data < root->data)
        {
                return tree_search(root->left,data);//Search in the left sub tree
        }
        else 
        {
		printf("Found: %c\n", data);
                return root;//character found
        }
}
//print inorder function
void tree_print_sorted(Tree_Node* root)
{
	if (root != NULL)
	{//displays left node, root node, right node
		tree_print_sorted(root->left);
		printf("%c \n", root->data);
		tree_print_sorted(root->right);
	}
}
void tree_delete(Tree_Node* root)
{
	if (root != NULL)
	{
		tree_delete(root->left);//call tree_delete while left subtree !=Null 
		tree_delete(root->right);//call tree_delete while right subtree !=Null 
		free(root);//delete node
	}
}
void selection_sort( char *array, int length ) 
{
	for ( int pass = 0; pass < length - 1; pass++ ) 
	{
		int min_idx = pass;
		for ( int i = pass + 1; i < length; i++ ) 
		{
			if ( array[i] < array[min_idx] ) 		
			{
				min_idx = i;
			}
		}
		int temp = array[min_idx];
		array[min_idx] = array[pass];
		array[pass] = temp;
	}
}
Tree_Node* newLeaf(char data)//makes a new node equal to data
{
	Tree_Node* root = (Tree_Node*)malloc(sizeof(struct Tree_Node));
	root->data = data;
	root->left = NULL;
	root->right = NULL;
	 
	return root;
}
Tree_Node* balanced_search_tree(char arr[], char start, char end)
{		
	if (start > end)//best case scenario
		return NULL;
 
  
	char middle = (start + end)/2;//mid point of a sorted array
    	Tree_Node *root = newLeaf(arr[middle]);//makes a node equal to the middle character
	
    
	root->left =  balanced_search_tree(arr, start, middle-1);//constructs subtree recursively to the left of the middle character i.e. characters < middle 
	root->right = balanced_search_tree(arr, middle+1, end);//constructs subtree recursively to the right of the middle character i.e. characters > middle 
 	
	return root;
}
//print in preorder function
void preorder(Tree_Node* root)
{
	if (root!= NULL)
	{//displays root node, left node, right node
		printf("%c ", root->data);
		preorder(root->left);
		preorder(root->right);
	}

void main()
{
	Tree_Node *treeA = NULL;
	
	char array1[] = {'X', 'Z', 'C', 'B', 'A', 'Y'};
	int length1 = sizeof(array1)/sizeof(array1[0]);

	for (int i = 0; i <= length1-1; i++)
	{
		tree_insert(&treeA, array1[i]);
	}

	tree_search(treeA, 'B');
	tree_print_sorted(treeA);
	printf("\n");

	char array2[] = {'X', 'Z', 'C', 'B', 'A', 'Y'};
	int length2 = sizeof(array2)/sizeof(array2[0]);

	selection_sort(array2, length2);

	Tree_Node *treeB = balanced_search_tree(array2, 0, length2-1);

	preorder(treeB);
	printf("\n");

	tree_delete(treeA);
	tree_delete(treeB);
	return;
}
