#pragma once

#define _membersOf(CLASS) \
	castsOf##CLASS; \
	fieldsOf##CLASS

#define membersOf(CLASS) \
	_membersOf(CLASS)
