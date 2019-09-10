#ifndef MS_ERROR_H
# define MS_ERROR_H
# include "mini.h"

#define FATAL_ME	1

#define ME_NLARG	"null argument"
#define ME_BADENV	"bad enviroment variable format"
#define ME_DIRERR	"error opening directory"
#define ME_CLSERR	"error closing directory stream"
#define ME_MEMERR	"error allocating memory"

void		mini_error(char *err_name, int flag);

#endif