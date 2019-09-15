#ifndef MS_ERROR_H
# define MS_ERROR_H
# include "mini.h"

#define NONFATAL_ME 0
#define FATAL_ME	1

#define ME_NLARG	"null argument"
#define ME_BADENV	"bad enviroment variable format"
#define ME_DIRERR	"error opening directory"
#define ME_CLSERR	"error closing directory stream"
#define ME_MEMERR	"error allocating memory"
#define ME_QOUTERR	"unmatched qoutes"

void 		mini_arr_error(char *err, char ***arrdel, int f);
void        mini_error(char *err, int f);

#endif