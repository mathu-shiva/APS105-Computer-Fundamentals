#include <stdio.h>
#include <stdlib.h>
#include "Contact_List.h"
#include <string.h>
#include <ctype.h>


// IF IT'S EASIER, YOU NEED NOT BE OVERLY GENERAL/FLEXIBLE
// BUT CAN ASSUME THESE LIMITS
#define MAXCONTACTS 30 /* max # of contacts */
#define MAXPHONES 10 /* max # of phone numbers for each contact */
#define PHONE_NUMBER_MAX_LENGTH 12

//void createNodeList(char *n,char *numbers,struct node** q);
//void createNodeList(char *n,char *number); // function to create the list
// INCLUDE YOUR OWN "HELPER" ROUTINES AS YOU SEE FIT
struct node
{
  char* contactName;
  char* phoneNumbers;
  struct node* link;
};


void   searchListbyName (struct node *q);

void   searchListbyName (struct node *q)
{
    struct node *temp;
    temp=q;
    char input[1024];
    char *str;
    int check=0;

    str=getString(input);

    while (temp!=NULL && check==0)
    {

        if (strcmp(temp->node.name,str)==0)
        {
            check=1;
        }
        else
        {
            temp=temp->link;
        }
    }

    if (check==1)
    {
        printf ("Contact found.");
        printBook(temp->node);
        printf("\n");
    }
    else
    {
        printf ("Contact not found.");
    }


}

void printContact(struct node)
{
    printf("\n%s", node.contactName);
    printf("\n%s", node.phoneNumbers);
}

void ListAllContacts()
{
   // YOUR CODE HERE
}



   
void createNodeList(char *n,char *numbers,struct node** q)
{
    /*printf(" n %s\n",n);
    printf(" numbers %s\n",numbers);*/
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->contactName = (char*) malloc(strlen(n)+1);
    strcpy(temp->contactName, n);
    temp->phoneNumbers = (char*) malloc(strlen(numbers)+1);
    strcpy(temp->phoneNumbers, numbers);
    temp->link = *q;
    *q = temp;     
}

void convertInputToDataStructure(struct node** q)
{
    int length = 0;
    length = sizeof (contactList)/sizeof (contactList [0]);    
    int j = 0; int k = 0;
    char name[256];
    char *phoneNumber[10]; //This is to read one phone number
    char *phoneNumberss[1200]; //List of multiple phone numbers to concatanate
    for(int i=0; i<length;i++)
    {    
        if(isalpha(contactList[i][0]))
        {                  
            if(k==1)
            {
                createNodeList(name,phoneNumberss,q); //Function to create a node and concatcntoae to thr linked list
                strcpy(phoneNumberss, ""); //Emptying the phone numbers array
                k=0;
            }
            strcpy(name, contactList[i]);
            k++;    
        }
        else
        {
            strcpy(phoneNumber, contactList[i]);
            strcat(phoneNumberss, phoneNumber);
            strcat(phoneNumberss, " ");
        }
        if (i== length-1){
            createNodeList(name,phoneNumberss,q);
        }
    }
}


void printList(struct node* q)
{
  if(q == NULL)
    {
     printf("\n\nNo data.\n\n");
    }
  else
    {
      printf("\n\n Name | Phone number \n");
      printf("---------------------------------\n");
      while(q != NULL)
      {
        printf("  %s   %s   \n",q->contactName,q->phoneNumbers);
        q = q->link;
      }
    }
}

int listLength(struct node* item)
{
  struct node* cur = item;
  int size = 0;
  while (cur != NULL)
  {
	++size;
    cur = cur->link;
  }
  return size;
}


void printMenu() {

   printf("\n\nEnter a command by number\n");

   printf("1. List all contacts in alphabetical order\n");

   printf("2. Print phone(s) for a contact\n");

   printf("3. Find duplicate entries\n");

   printf("4. Delete contact\n");

   printf("5. Exit the program\n");

   printf("Your input: ");

}

 

//eliminate trailing \n

char* rtrim(char* str)

{

   int i;

   for (i = strlen(str) - 1; i >= 0 && str[i] == '\n'; i--)

      str[i] = '\0';

   return str;

}

 

void PrintContact() {
	
}


 

 

/*

* DeleteContact deletes a contact from the list

* The user must enter the name of the contact to delete

*

 */

 

void DeleteContact() {

    // YOUR CODE HERE

}

 

 

/*

* findDuplicates finds the names of contacts with

 * a phone number in common

*/

 

void FindDuplicates() {

   

    // YOUR CODE HERE

 

}

 

int main()

{

    struct node *p;

    p = NULL; //so p is the head of an empty list

   // first move data from contactList.h to a data structure

    convertInputToDataStructure(&p);

   printList(p);

   int listLengths = 0;

   listLengths = listLength(p);

   //sorting  

   printf("selection = %d\n", listLengths);

   /*for (int i = 0; i < HOW_MANY ; i++) {

        headptr = insert_sorted(headptr, names[i], ages[i]);

    }*/

  

   

   char notDone = 1;

   while (notDone) {

      printMenu();

      char userChoice[100];

      char* s = fgets(userChoice, sizeof(userChoice), stdin);

      if (!s)

      {

         printf("Wrong input\n");

         continue;

      }

      s = rtrim(s); /* eliminate trailing \n */

      //printf("selection = %s\n", s);

      int userSelection = atoi(s);

 

      switch (userSelection) {

         case 1: ListAllContacts(); break;

         case 2: PrintContact(); break;

         case 3: FindDuplicates(); 
		 // Search for a contact by a name.
            printf("\nEnter the contact name to search for: ");
            searchListbyName(head);
		 break;

         case 4: DeleteContact(); break;

         case 5: notDone = 0; break;

         default: printf("Bad command...\n"); break;

         }

    

   }

  

   // PUT ANY POST_RUN CODE HERE

 

   return 0;

}
