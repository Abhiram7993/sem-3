#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int c;
	int e;
	struct node* next;
}node;

// linked list 1, 2 and result
node *p1 = NULL;
node *p2 = NULL;
node *result = NULL;
int n1, n2;

// function insert node in linked list
void insert_node(node** p, int c, int e);
void flush(void);


int main(void){
	printf("Enter number of elements in P1: ");
	scanf("%i", &n1);
	flush();
	
	// reading elements in polynomial 1
	int i = 0;
	while (i<n1){
		int c, e;
		printf("Enter coefficient: ");
		scanf("%i", &c);
		flush();
		
		printf("Enter exponent: ");
		scanf("%i", &e);
		flush();
		
		insert_node(&p1, c, e);
		i++;	
	}
	
	// reading elements in polynomial 2
	printf("Enter number of elements in P2: ");
	scanf("%i", &n2);
	flush();
	
	int j = 0;
	while (j<n2){
		int c, e;
		printf("Enter coefficient: ");
		scanf("%i", &c);
		flush();
		
		printf("Enter exponent: ");
		scanf("%i", &e);
		flush();
		
		insert_node(&p2, c, e);
		j++;	
	}
	
	// multiplying two polynomials
	node *temp1, *temp2;
	int c, e;
	temp1 = p1;
	temp2 = p2;
	
	if (temp1 == NULL || temp2 == NULL){
		printf("Resultant is empty polynomial.\n");
		return 0;
	}
	
	while (temp1 != NULL){
		temp2 = p2;
		while (temp2 != NULL){
			c = temp1->c * temp2->c;
			e = temp1->e + temp2->e;
			insert_node(&result, c, e);
			temp2 = temp2->next;
		}
		temp1 = temp1->next;
	}
	
	node* temp3 = result;
	while (temp3 != NULL){
		printf("%ix^%i + ", temp3->c, temp3->e);
		temp3 = temp3->next;
	}
	printf("\n");
	return 0;
}


void flush(void){
	int c = getchar();
	while (c!='\n' && c!=EOF){
		c = getchar();
	}
}


void insert_node(node** p, int c, int e){
	node* newnode = (node*)malloc(sizeof(node));
	newnode->c = c;
	newnode->e = e;
	
	if (*p == NULL){
		newnode->next = *p;
		*p = newnode;
		return;
	}
	
	if (e > (*p)->e){
		newnode->next = *p;
		*p = newnode;
		return;
	}
	
	// If both have same exponent
	if (e == (*p)->e){
		if ((*p)->c + c != 0)
			(*p)->c = (*p)->c + c;
		
		else
			(*p) = (*p)->next;
		
		free(newnode);
		return;
	}
	
	node* temp = *p;
	while (temp->next!=NULL && temp->next->e > e){
		temp = temp->next;
	}
	
	if (temp->next == NULL){
		newnode->next = temp->next;
		temp->next = newnode;
		return;
	}
	
	else {
		if (temp->next->e == e){
			if (temp->next->c + c != 0){
				temp->next->c = temp->next->c + c;
				free(newnode);
				return;
			}
			else{
				temp->next = temp->next->next;
				return;
			}
		}
		else{
			newnode->next = temp->next;
			temp->next = newnode;
			return;
		}
	}
	
}




























































































