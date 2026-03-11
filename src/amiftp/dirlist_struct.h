/* RCS Id:  $Id: dirlist_struct.h 1.587 1996/06/14 13:23:25 lilja Exp $
   Locked version: $Revision: 1.587 $
*/

#ifndef __DIRLIST_STRUCT_H__
#define __DIRLIST_STRUCT_H__

#include <stddef.h>
#ifndef _MODE_T_DEFINED
typedef unsigned long mode_t;
#define _MODE_T_DEFINED
#endif

#define	DATELEN 20

struct dirlist {
    char	*name;
    char	*date;
    char	*owner;
    char	*group;
    char        *lname;
    mode_t	 mode;
    int          link:1;
    int          file:1;
    int          dir:1;
    int          adt:1;
    int          new:1;
    int          hide:1;
    int          readmelength;
    int          readmelen;
    ULONG        adtdate;
    size_t	 size;
};

#define	SORTBYNAME	0
#define	SORTBYDATE	1
#define	SORTBYSIZE	2

#define	ASCENDING	0
#define	DESCENDING	1

#define	GROUPBYTYPE 0
#define	GROUPNONE	1

#endif /* __DIRLIST_STRUCT_H__ */
