#pragma once

#include "Employee.h"

typedef struct Manager
{
#define castsOfManager \
	Employee Employee[0]; \
	castsOfEmployee

#define fieldsOfManager \
	fieldsOfEmployee; \
	Employee* m_reports

    membersOf(Manager);
} Manager;

