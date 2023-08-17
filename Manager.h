#pragma once

#include "Employee.h"

//#define castsOfManager(BASE)
#define castsOfManager \
	Employee Employee[0]; \
	castsOfEmployee

//#define fieldsOfManager(BASE)
#define fieldsOfManager \
	fieldsOfEmployee; \
	Employee* m_reports

//#define membersOfManager(BASE)
#define membersOfManager \
	castsOfManager; \
	fieldsOfManager

typedef struct Manager
{
    membersOfManager;
} Manager;
