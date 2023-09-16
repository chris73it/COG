#pragma once

#include "Void.h"

typedef struct Object
{
#define castsOfObject \
	Void Void[0]

#define fieldsOfObject \
	void* vptr

    membersOf(Object);
} Object;

