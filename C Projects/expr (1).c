#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "expr.h"

char* makeString(char* s1, char* s2, char* s3)
{
	int size1 = strlen(s1);
	int size2 = strlen(s2);
	int size3 = strlen(s3);
	int sizeN = size1 + size2 + size3 + 1;
	char *newS = malloc(sizeN * sizeof(char));
	strcpy(newS,s1);
	newS = strcat(newS,s2);
	newS = strcat(newS,s3);
	return newS;
}

Node* createNode(char* s, double val)
{
	Node *node = malloc(sizeof(Node));
	if (node == NULL)
	{
		return NULL;
	}
	if (s == NULL)
	{
		return NULL;
	}
	if (node == NULL)
	{
		return NULL;
	}
	node->expr_string = s;
	node->num_parents = 0;
	node->left = NULL;
	node->right = NULL;
	node->value = val;
	return node;
}

Node* binop(Operation op, Node* a, Node* b)
{
	if (a->num_parents == 1 || b->num_parents == 1)
	{
		return NULL;
	}
	Node *bnode = malloc(sizeof(Node));
	if (bnode == NULL)
	{
		return NULL;
	}
	bnode->operation = op;
	bnode->num_parents = 0;
	bnode->left = a;
	bnode->right = b;
	(bnode->left)->num_parents++;
	(bnode->right)->num_parents++;
	char *astr = "";
	char *bstr = "";
	switch (bnode->operation)
	{
		case addop:
			bnode->expr_string = makeString(a->expr_string,"+", b->expr_string);
			break;
		case subop:
			bnode->expr_string = makeString(a->expr_string, "-", b->expr_string);
			break;
		case mulop:
			astr = makeString("(",a->expr_string,")");
			bstr = makeString("(",b->expr_string,")");
			bnode->expr_string = makeString(astr, "*", bstr);
			free(astr);
			free(bstr);
			break;
		case divop:
			astr = makeString("(",a->expr_string,")");
			bstr = makeString("(",b->expr_string,")");
			bnode->expr_string = makeString(astr, "/", bstr);
			free(astr);
			free(bstr);
			break;
	}
	bnode->value = evalTree(bnode);
	return bnode;
}

double evalTree(Node *root)
{
	if (root->left == NULL && root->right == NULL)
	{
		return root->value;
	}
	double lvalue = evalTree(root->left);
	double rvalue = evalTree(root->right);
	if (root->operation == addop)
	{
		return lvalue + rvalue;
	}
	if (root->operation == subop)
	{
		return lvalue - rvalue;
	}
	if (root->operation == mulop)
	{
		return lvalue * rvalue;
	}
	if (root->operation == divop)
	{
		return lvalue / rvalue;
	}
	else
	{
		return 0.0;
	}
}


void freeTree(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	freeTree(root->left);
	freeTree(root->right);
	/*free(root->expr_string);*/
	free(root);
}

Node* duplicateTree(Node *root)
{
	if (root == NULL)
	{
		return root;
	}
	Node *clone = (Node*)malloc(sizeof(Node));
	if (clone == NULL)
	{
		return NULL;
	}
	clone->operation = root->operation;
	clone->value = root->value;
	clone->expr_string = root->expr_string;
	clone->num_parents = root->num_parents;
	clone->left = duplicateTree(root->left);
	clone->right = duplicateTree(root->right);
	return clone;
}

void printTree(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	printf("Node\n");
	printf("\texpr_string = %s\n", root->expr_string);
	printf("\tvalue       = %g\n", root->value);
	printf("\tnum_parents = %d\n", root->num_parents);
	printTree(root->left);
	printTree(root->right);
}


