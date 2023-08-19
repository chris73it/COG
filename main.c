#include <stdlib.h>
#include <stdio.h>
#include "Manager.h"

void work(Employee* empl)
{
    printf("The Employee Id is %d.\n", empl->m_id);
}

int main()
{
	int x = 8;
	int* px = &x;
	int* px2 = &px[1];
	int** px3 = &px;

    Employee* empl = (Employee*) malloc(sizeof(Employee));
    empl->m_id = 1;
    work(empl);

	Employee empl2;
	empl2.m_id = 2;
    work(&empl2);

	Employee empl3[1];
	empl3->m_id = 3;
    work(empl3);

    Manager* boss = (Manager*)malloc(sizeof(Manager));
    boss->m_id = 4;
    work( (Employee*)boss ); //NOT Type Safe !!!
    work(boss->Employee);   //         Type Safe !!!

	Manager boss2;
	boss2.m_id = 5;
    work(boss2.Employee);

	Manager boss3[1];
	boss3->m_id = 6;
    work(boss3->Employee);

    printf("Address of empl is        %p.\n", empl);
    printf("Address of empl->vptr is  %p.\n", &empl->vptr);

    printf("Address of empl2 is       %p.\n", &empl2);
    printf("Address of empl2->vptr is %p.\n", &empl2.vptr);

    printf("Address of empl3 is       %p.\n", empl3);
    printf("Address of empl3->vptr is %p.\n", &empl3->vptr);

    printf("Address of boss is                 %p.\n", boss);
    printf("Address of boss->vptr is           %p.\n", &boss->vptr);
    printf("Address of boss->Employee->vptr is %p.\n", &boss->Employee->vptr);

    return 0;
}
