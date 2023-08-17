#include <stdlib.h>
#include <stdio.h>
#include "Manager.h"

void work(Employee* empl)
{
    printf("The Employee Id is %d.\n", empl->m_id);
}

int main()
{
    Employee* empl = (Employee*) malloc(sizeof(Employee));
    empl->m_id = 1;
    work(empl);

    Manager* boss = (Manager*)malloc(sizeof(Manager));
    boss->m_id = 2;
    work( (Employee*)boss ); //NOT Type Safe !!!
    work(boss->Employee);    //    Type Safe !!!

    printf("Address of empl is       %p.\n", empl);
    printf("Address of empl->m_id is %p.\n", &empl->m_id);

    printf("Address of boss is       %p.\n", boss);
    printf("Address of boss->m_id is %p.\n", &boss->m_id);
    printf("Address of boss->Employee->m_id is %p.\n", &boss->Employee->m_id);

    return 0;
}
