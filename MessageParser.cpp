#include "header.h"

struct Node* head = NULL; //pointer to head of the linked list

bool check_header(char * message_buffer)
{
	return HEADER_ID == get_field_value(message_buffer, 'h'); //get field type header and verify with header id	
}

uint16_t get_field_value(char *message_buffer, char field_type)
{
        char field_str[FIELD_SIZE];

        uint16_t field_value = 0, k = 0, init_field = -1;

	switch(field_type) {
		case 'h': //header
			init_field = 0;
			break;
		case 'S': //speed
			init_field = 1;
			break;
		case 'D': //heading
			init_field = 2;
			break;
		case 'A': //altitude
			init_field = 3;
			break;
		case 'c': //checksum
			init_field = 4;
			break;
	}

	if(init_field == -1)
		return -1;

        for(int i = init_field*FIELD_SIZE; i < (init_field+1)*FIELD_SIZE; i++)
        {
                field_str[k++] = message_buffer[i];
        }
        field_str[k] = '\0';

        field_value = (uint16_t)strtol(field_str, NULL, 16); // number base 16

        return ntohs(field_value);
}

uint16_t get_calculated_checksum(char *message_buffer)
{
	long byte_value = 0;
	unsigned short k = 0;
	char byte_str[FIELD_SIZE/2];
	char checksum_str[FIELD_SIZE];

	for(int i = FIELD_SIZE; i < 4*FIELD_SIZE; i++)
	{
		byte_str[k++] = message_buffer[i];
		if(k%2 == 0 && k != 0)
		{
			byte_str[k] = '\0';
			k = 0;
			byte_value += strtol(byte_str, NULL, 16);
		} 	
	}

	sprintf(checksum_str, "%X", (uint16_t)byte_value); 

	return  (uint16_t) strtol(checksum_str, (char **)NULL, 16);
}

/* Given a reference (pointer to pointer) to the head 
   of a list, values to add, appends a new node at the end  */
void append(struct Node** head_ref, float speed, uint16_t heading, float altitude) 
{ 
    /* 1. allocate node */
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
  
    struct Node *last = *head_ref; 
  
    /* 2. put in the data  */
    new_node->speed    = speed;
    new_node->heading  = heading;
    new_node->altitude = altitude; 
  
    /* 3. This new node is going to be the last node, so make next of 
          it as NULL*/
    new_node->next = NULL; 
  
    /* 4. If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL) 
    { 
       *head_ref = new_node; 
       return; 
    } 
  
    /* 5. Else traverse till the last node */
    while (last->next != NULL) 
        last = last->next; 
  
    /* 6. Change the next of last node */
    last->next = new_node; 
    return; 
} 

// This function prints contents of linked list starting from head 
void printList(struct Node *node) 
{ 
  while (node != NULL) 
  { 
     cout << "Speed: " << node->speed << " Heading: " << node->heading << " Altitude: " << node->altitude << endl; 
     node = node->next; 
  } 
}

bool parse_message(char *message_buffer, uint16_t message_size)
{
	if(sizeof(message_data) != message_size)
	{
		cout << "Message size is not as expected" << endl;
		return 0;
	}

	/* Start with the empty list */
  	head = NULL;

	/* Verify the header of the message and make sure the checksum is matched */
	if(check_header(message_buffer) == 1 && get_field_value(message_buffer, 'c') == get_calculated_checksum(message_buffer))
	{
		cout << "Speed: " << endl;
		cout << get_field_value(message_buffer, 'S') << endl; //parse field type Speed

		cout << "Heading: " << endl;
		cout << get_field_value(message_buffer, 'D') << endl; //parse field type Heading
		
		cout << "Altitude: " << endl;
		cout << get_field_value(message_buffer, 'A') << endl; //parse field type Altitude

		float speed_kmh = (float) get_field_value(message_buffer, 'S') * 60 / 1000; //convert m/s to km/h
		float altitude_meters = (float) get_field_value(message_buffer, 'A') / 100; // convert cm to meter

		append(&head, speed_kmh, get_field_value(message_buffer, 'D'), altitude_meters); //add to the linked list
	
		return 1;
	}
	else {
		cout << "Either header or checksum is incorrect" << endl;
		return 0;
	}

	return 0;
}

int main()
{
	//char *message =   (char *)"05080000000000000000";

	char *message = (char *)"05080100020004000700";
	
	//char *message = (char *)"05080500090007001500";

	//char *message = (char *)"05081500190017004500";

	//char *message = (char *)"05084710290097051C01";

	//char *message = (char *)"0508FFFFFFFFFFFFFA05";

	//char *message = (char *)"0508FA2FF3CF1EFF0804";

  	//char *message = (char *)"05080100000000101100";

	uint16_t message_length = 10;

	cout << "Input message: " << message << " Message Length: " << message_length << endl;

	if(parse_message(message, message_length) == 1)
	{
		cout << endl << "Created Linked list is:" << endl;
	        printList(head);
	}
	else {
		cout << "Error occurred during parsing" << endl;
	}

	return 0;
}

Corresponding header file: header.h
--------------------------
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <netinet/in.h>

using namespace std;

#define HEADER_SIZE 4 //message header size is 2 bytes
#define FIELD_SIZE 4 //each field size is 2 bytes long

#define HEADER_ID 2053 // "0508"

bool check_header(char * message_buffer);
uint16_t get_field_value(char *message_buffer, char field_type);
uint16_t get_calculated_checksum(char *message_buffer);
bool parse_message(char *message_buffer, int message_size);
void printList(struct Node *node);

struct message_data
{
	uint16_t msg_header;
	uint16_t speed; //in meter/sec
	uint16_t heading; //in degrees
	uint16_t altitude; //in centimeter
	uint16_t checksum;
};

struct Node
{
        float speed; //in km/hour
        uint16_t heading; //in degrees
        float altitude; //in meter
	struct Node *next;
};
