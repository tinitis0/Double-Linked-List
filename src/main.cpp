/**
@file main.cpp
*/

/*! \mainpage Lab Book 3
 *
 * Implementation of a Double Linked List
 */

// Define and includes to show memory leak report
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

#include <iostream>
#include "doubleLinkedList.h"



void main()   /** Entry point for the application */
{
	doubleLinkedlist dll;

	dll.addFromHead(3);
	dll.addFromHead(7);
	dll.addFromHead(2);
	dll.addFromHead(8);
	dll.addFromHead(1);
	dll.addFromHead(9);
	dll.addFromHead(4);
	dll.addFromHead(6);
	dll.addFromHead(5);
	dll.printFromHead();
	dll.printFromTail();
	

	_CrtDumpMemoryLeaks(); // Look in the output window for a report
	system("pause");
}
