#include <stddef.h>
#include <stdlib.h>
#include <string.h>

#include "ares.h"
// Include ares internal file for DNS protocol constants
#include "ares_nameser.h"

// Entrypoint for Clang's libfuzzer, exercising query creation.
int LLVMFuzzerTestOneInput(const unsigned char *data,
                           unsigned long size) {
  // Null terminate the data.
  char *name = malloc(size + 1);
  name[size] = '\0';
  memcpy(name, data, size);

  unsigned char *buf = NULL;
  int buflen = 0;
  ares_create_query(name, C_IN, T_AAAA, 1234, 0, &buf, &buflen, 1024);
  free(buf);
  free(name);
  return 0;
}

#if defined(__QNXNTO__) && defined(__USESRCVERSION)
#include <sys/srcversion.h>
__SRCVERSION("$URL: http://f27svn.qnx.com/svn/repos/osr/trunk/cares/dist/test/ares-test-fuzz-name.c $ $Rev: 4177 $")
#endif
