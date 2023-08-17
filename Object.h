#pragma once

#include "Void.h"

#define castsOfObject \
	Void Void[0]

//#define fieldsOfObject(BASE)
#define fieldsOfObject \
	void* vptr

//#define membersOfObject(BASE)
#define membersOfObject \
	castsOfObject; \
	fieldsOfObject

struct Object
{
    membersOfObject;
};

typedef struct Object Object;
