#include<stdio.h>
#include<stdlib.h>

struct GTnode
{
    char* data;
    int children,level;
    struct GTnode** child;
};

void createGT(struct GTnode*);
void display(struct GTnode*);

void main()
{
    struct GTnode* root = NULL;
    char ch;
    int i,size;
    printf("********* General Tree ****************\n");
    
    root = (struct GTnode*) malloc(sizeof(struct GTnode));

	size=1;
    root->data=(char*)malloc(size*sizeof(char));
	*(root->data)='\0';
	printf("Enter Book Name = ");
	i=0;
	do
	{	
		scanf("%c",&ch);
		if(ch != '\n')
		{
			root->data=(char*)realloc(root->data,(size++)*sizeof(char));
			*((root->data)+i)=ch;
			*((root->data)+(i+1))='\0';
			i++;		
		}
	}while(ch!='\n');

    printf("How many Sub-Topics in Book : ");
    scanf("%d",&(root->children));

    root->child = (struct GTnode**) malloc ((root->children) * sizeof(struct GTnode*));
    root->level = 1;

    createGT(root);
    printf("----------------------------------------------------------------\n%s\n",root->data);
    display(root);
}

void createGT(struct GTnode* root)
{
    int children,i,size;
    char ch;
    for(children = 0 ; children < (root->children) ; children++)
    {
        struct GTnode* tempnode = NULL;
        tempnode = (struct GTnode*) malloc (sizeof(struct GTnode));
        getchar();
	    size=1;
        i=0;
        tempnode->data=(char*)malloc(size*sizeof(char));
	    *(tempnode->data)='\0';
	    printf("Enter Sub-Topic %d of %s = ",children+1,root->data);
	    do
	    {	
		    scanf("%c",&ch);
		    if(ch != '\n')
		    {
			    tempnode->data=(char*)realloc(tempnode->data,(size++)*sizeof(char));
			    *((tempnode->data)+i)=ch;
			    *((tempnode->data)+(i+1))='\0';
			    i++;		
		    }
	    }while(ch!='\n');

        printf("How many Sub-Topics of %s : ",tempnode->data);
        scanf("%d",&(tempnode->children));

        tempnode->child = (struct GTnode**) malloc ((tempnode->children) * sizeof(struct GTnode*));
        tempnode->level = (root->level) + 1;

        root->child[children] = tempnode;

    }   

    for(children=0;children<root->children;children++)
        createGT(root->child[children]) ;
}

void display(struct GTnode* root)
{
    int i,j;
    for(i=0;i<root->children;i++)
    {    
        for(j=0;j<root->level;j++)
            printf("\t");
        printf("%d. %s\n",i+1,root->child[i]->data);
        display(root->child[i]);
    }
}