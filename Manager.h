#pragma once

#include "Employee.h"

#define castsOfManager \
	Employee Employee[0]; \
	castsOfEmployee

#define fieldsOfManager \
	fieldsOfEmployee; \
	Employee* m_reports

typedef struct Manager
{
    membersOf(Manager);
} Manager;