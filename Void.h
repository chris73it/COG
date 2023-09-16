#pragma once

typedef struct Void
{
#define _membersOf(CLASS) \
	castsOf##CLASS; \
	fieldsOf##CLASS

#define membersOf(CLASS) \
	_membersOf(CLASS)

} Void;

