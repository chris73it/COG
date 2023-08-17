#pragma once

#include "Object.h"

#define castsOfEmployee \
	Object Object[0]; \
	castsOfObject

//#define fieldsOfEmployee(BASE)
#define fieldsOfEmployee \
	fieldsOfObject; \
	unsigned int m_id

//#define membersOfEmployee(BASE)
#define membersOfEmployee \
	castsOfEmployee; \
	fieldsOfEmployee

typedef struct Employee
{
    membersOfEmployee;
} Employee;
