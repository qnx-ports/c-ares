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

#ifndef __QNX_FUNC_H
#define __QNX_FUNC_H

static char * getconf(int token);
static int res_conf_str_used_and_differs(const char * previous_value, int token);

#endif