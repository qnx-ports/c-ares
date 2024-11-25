/***
 * When updating this port to work with the recursive file system and with the newer version, I foudn these functions.
 * I'm pretty sure these are part of libsocket, but adding -lsocket to the compiler options in configure.ac did not
 * work. They really do not belong in the c-ares code but seem to be necessary despite the code duplication - I would recommend
 * looking into fixing this.
 * 
 * I'm pretty sure this is just a lapse in my knowledge of QNX, so hopefully it is an easy fix.
 * 
 * Best of luck! -JM
 */

#include "ares_private.h"

#ifdef HAVE_SYS_PARAM_H
#  include <sys/param.h>
#endif

/* CODE DUPLICATION WARNING: This code is a duplicate of code in
 * libsocket (resolve/res_init.c) */
static char *
getconf(int token)
{
  size_t len;
  char *buf;
  char *cp;

  if((len=confstr(token,NULL,0))==0) {
    return(NULL);  /* Token not set */
  }

  if((buf=malloc(len))==NULL)
    return(NULL);
  if(confstr(token,buf,len)==0){
    *buf = '\0';
  }

  cp=buf;
  while(*cp != '\0'){
    if(*cp=='_')
    *cp=' ';
    cp++;
  }

  return(buf);
}


/* CODE DUPLICATION WARNING: This code is a duplicate of code in
 * libsocket (resolve/res_init.c) */
/* returns 1 if the values differ, 0 otherwise */
static int
res_conf_str_used_and_differs(const char * previous_value, int token)
{
  if (previous_value == NULL || previous_value[0] == '\0') {
    /* We never used the previous value, so we must be loading via
     * another technique or the value has changed. Do not cause
     * needs_reload() to return 0 as a timeout may have occured.
     */
    return 1;
  }

  char * current_value = getconf(token);
  if (NULL == current_value || current_value[0] == '\0') {
    /* We could not get a value, or we ran into a memory issue of
     * some sort. Do not cause needs_reload() to return 0 as a
     * timeout may have occured.
     */
    return 1;
  }

  int res = (strcmp(previous_value, current_value) == 0) ? 0 : 1;
  free(current_value);
  return res;
}

