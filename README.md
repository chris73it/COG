# COG
C Object Generator: a compile-time type-safe object model in C without the need for extra preprocessors

So far, all C language object models fall into one of two categories:
A. Object models that use void pointers (void*) generously, so the user doesn't have to constantly cast types:
  I. This has the advantage of being more convenient.
  II. This has the disadvantage of NOT being compile-time type-safe.
  NOTE Type-safety can be achieved at runtime, but it consumes CPU cycles and usually requires adding a tag field to every object to compare against, consuming extra memory.
B. Object models that do NOT use void pointers everywhere:
  I. This has the disadvantage of requiring casts everywhere.
  II. Again, this is NOT compile-time type-safe.
  NOTE: As for case A, case B can be made type-safe at runtime, again at the cost of using extra cycles and memory.

COG is different because it obliges users to use casts, but these casts are compile-time type-safe, in the sense that using an incompatible cast, causes a compile-time error.

How does it work? Imagine a Manager struct that derives from an Employee struct:
#include <stdlib.h>
#include <stdio.h>
#include "Object.h"

//Employee derives from Object
typedef struct Employee
{
    Object Object[0];
    void* vptr;
    unsigned int m_id;
} Employee;

//Manager derives from Employee
typedef struct Manager
{
    Employee Employee[0];
    Object Object[0];
    void* vptr;
    unsigned int m_id;
    Employee* m_reports;
} Manager;

I define a work function that takes an Employee pointer in input:
void work(Employee* empl)
{
    printf("The Employee Id is %d.\n", empl->m_id);
}

Now, from main() I can pass either an Employee object or a Manager object to work() in a compile-time type-safe way:
int main()
{
  Employee* empl = (Employee*)malloc(sizeof(Employee));
  /*1*/ work(empl); //OK, of course it works.

  Manager* boss = (Manager*)malloc(sizeof(Manager));
  /*2*/ work(boss); //ERROR: Expecting Employee* but getting Manager*
  /*3*/ work(boss->Employee); //OK, a Manager is-an Employee (!!)
  /*4*/ work(boss->Banana); //ERROR: Manager does not derive from Banana (!!)
  /*5*/ int x=7; work(&x); //ERROR: Expecting Employee* but getting int*
  return 0;
}

By unconventionally using zero-size arrays at the start of a struct definition (instead of at the bottom of it,)
we use the corresponding array name as a way to implement compile-time type-safe upcasts (!!)

Let's go through all 5 cases and comment on each:
1. OK. Of course, passing an Employee* to a function that expects an Employee* is going to work (no pun intended)
2. ERROR. Even though compilers for languages like C++ and Java accept this case without having to explicitly upcast (what we achieve by adding a ->Employee after boss).
   this case is treated as an error: notice that, even though it is bothersome having to add ->Employee at the end, it is still, albeit very conservatively, compile-time type-safe.
3. OK. We are using the power of zero-sie arrays at the top of a struct definition to - as a matter of fact - implement compile-time type-safe upcasts (!!)
4. ERROR. I imagined that there is an unrelated Banana struct, and because Manager does NOT derive from it, it does NOT have a Banana Banana[0] zero-size array at the top, hence it cannot be upcast to it.
5. ERROR. The Manager struct does NOT have an int int[0] zero-size array at the top (because it does not derive from it) hence a Manager cannot be upcast to int.

Pretty much I cannot think of any other way to try to trick the C compiler into doing the wrong thing, and so - even though  case 2 requires a redundant ->Employee that is not required in C++ 
and Java - COG is compile-time type-safe.

NOTE This consumes no extra CPU cycles at runtime, since all checks are performed by the C language, and there is no need to manually add a tag, that would consume extra memory.
NOTE Finally, note that this could be retrofitted into existing C language object models while maintaining both source code and binary backward compatibility.

Remember you read it here first :-)
