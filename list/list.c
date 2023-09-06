#include "list.h"

enum OPTION
{
    EXIT,
    PUSH_FRONT,
    PUSH_BACK,
    DELETE,
    PRINT
};

void allocateMemory(Node** nodeToAllocate)
{
    (*nodeToAllocate) = (Node*)malloc(sizeof(Node));
}

Node* pushAtFrontOfList(int data)
{
    if (!first)
    {
        allocateMemory(&first);
        first->data_ = data;
        first->next_ = NULL;
    }
    else
    {
        allocateMemory(&current);
        current->data_ = data;
        current->next_ = first;
        first = current;
    }

    return first;
}

Node* pushAtBackOfList(int data)
{
    Node* last;
    if (!first)
    {
        allocateMemory(&first);
        first->data_ = data;
        first->next_ = NULL;
    }
    else
    {
        allocateMemory(&current);
        current->data_ = data;
        current->next_ = NULL;
        allocateMemory(&last);
        last = first;
        while(last->next_)
        {
            last = last->next_;
        }
        last->next_ = current;
    }

    return first;
}

void deleteNode(int dataToDelete)
{
    Node* auxiliary = first;
    Node* toDelete;
    if (!first)
    {
        printf("List is empty, there is nothing to delete!\n");
        return;
    }
    if ((first->data_) == dataToDelete)
    {
        toDelete = first;
        first = first->next_;
        free(toDelete);
        printf("Element \"%d\" was deleted!\n", dataToDelete);
        return;
    }
    else
    {
        while(auxiliary->next_)
        {
            if ((auxiliary->next_->data_) == dataToDelete)
            {
                toDelete = auxiliary->next_;
                auxiliary->next_ = toDelete->next_;
                free(toDelete);
                printf("Element \"%d\" was deleted!\n", dataToDelete);
                return;
            }
            auxiliary = auxiliary->next_;
        }
        printf("Element \"%d\" was not found in the list!\n", dataToDelete);
    }
}

void printList()
{
    Node* toPrint = first;
    if (!toPrint)
    {
        printf("List is empty!\n");
        return;
    }
    while (toPrint)
    {
        printf("%d ", toPrint->data_);
        toPrint = toPrint->next_;
    }
    printf("\n-------------------\n");
}

void printMenu()
{
    printf("0. Exit\n");
	printf("1. Add number in the front of the list\n");
	printf("2. Add number in the back of the list\n");
	printf("3. Remove number from list\n");
	printf("4. Print list\n");
}

int askForOption()
{
    int option;
    printf("Enter your option: ");
	scanf("%d", &option);

    return option;
}

int askWhatToAdd()
{
    int data;
    printf("Enter the data that you want to add in the list: ");
    scanf("%d", &data);

    return data;
}

int askWhatToDelete()
{
    int dataToDelete;
    printf("Enter the data that you want to delete from the list: ");
    scanf("%d", &dataToDelete);

    return dataToDelete;
}

int main()
{
    while (1)
	{
		printMenu();
		switch (askForOption())
		{
		    case EXIT:
		    {
		    	exit(0);
		    	break;
		    }
		    case PUSH_FRONT:
		    {
		    	first = pushAtFrontOfList(askWhatToAdd());
		    	break;
		    }
		    case PUSH_BACK:
		    {
		    	first = pushAtBackOfList(askWhatToAdd());
		    	break;
		    }
		    case DELETE:
		    {
		    	deleteNode(askWhatToDelete());
		    	break;
		    }
		    case PRINT:
		    {
		    	printList();
		    	break;
		    }
            default:
            {
                printf("Enter a valid option!\n");
                break;
            }
		}
	}

	return 0;
}