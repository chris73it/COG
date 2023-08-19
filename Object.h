#pragma once

#include "Void.h"

#define castsOfObject \
	Void Void[0]

#define fieldsOfObject \
	void* vptr

typedef struct Object
{
    membersOf(Object);
} Object;
