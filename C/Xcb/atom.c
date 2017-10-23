#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <xcb/xcb.h>
#include <X11/Xlib.h>
#define  NUM_NAMES 500
/*
  NOTE: For concision, we use arrays where  would be points and memory aloc.s
*/
#ifndef __GNUC__
char* strdup(const char* s){
  int n = strlen(s) + 1;

  char *dup = malloc(n);

  if(dup){
    strcpy(dup, s);
  }
  return dup;
}
#endif

/* NOTE: return interval of time(uses time.h)*/

double get_time(void){
  struct timeval timev;
  gettimeofday(&timev, NULL);
  return (double)timev.tv_sec + (((double)timev.tv_usec)/1000000);
}

/*
*/
void useXlib(char **names, Display *display) {
  Atom atoms[NUM_NAMES];
  for (int i = 0; i < NUM_NAMES; i++) {
    atoms[i] = XInternAtom(display, names[i], 0);
  }
}

/* Request all atoms at once.*/
void useXlibProperly(char **names, Display *display) {
  Atom atoms[NUM_NAMES];
  if (!XInternAtoms(display, names, NUM_NAMES, 0, atoms)) {
    fprintf(stderr, "XInternAtoms failed\n");
  }
}
void useXCBPoorly(char **names, xcb_connection_t *connection) {
  xcb_atom_t atoms[NUM_NAMES];
  // In this bad use of xcb, we use the cookie immediatlely after posting the
  // request with xcb_intern_atom.
  for (int i = 0; i < NUM_NAMES; i++) {
    /* make request */
    xcb_intern_atom_cookie_t cookie = xcb_intern_atom(connection, 0, strlen(names[i]),
                                             names[i]);
    /* get response */
    // normally a pointer to receive error, but we'll just ignore error handling
    xcb_intern_atom_reply_t *reply = xcb_intern_atom_reply(connection, cookie, NULL);

    if (reply) {
      atoms[i] = reply->atom;
      free(reply);
    }
  }
  // Now we have our atoms (relies), but this is just a demo, so we do nothing
}

void useXCBProperly(char **names, xcb_connection_t *connection) {
  xcb_atom_t atoms[NUM_NAMES];
  xcb_intern_atom_cookie_t cookies[NUM_NAMES];
  // In this good example, we requests before checking for replies because it's
  // best to queuerequests when we have many at once.
  /* NOTE:make requests */
  for (int i = 0; i < NUM_NAMES; i++) {
    cookies[i] = xcb_intern_atom(connection,0,strlen(names[i]),names[i]);
  }
  /*NOTE: get responses */
  for (int i = 0; i < NUM_NAMES; i++) {
    // normally a pointer to receive errors, but we'll just ignore err handling.
    xcb_intern_atom_reply_t *reply = xcb_intern_atom_reply(connection, cookies[i], NULL);

    if (reply) {
      atoms[i] = reply->atom;
      free(reply);
    }
  }
  // now we have our atoms (replies), but this is just a demo.
}
int main() {
  /* setup names for tests */
  char (**names) = malloc(NUM_NAMES*sizeof(*names));
  // init names to "NAME0", "NAME1", "NAME2" ... and so on
  for (int i = 0; i < NUM_NAMES; i++) {
    char buf[100];
    sprintf(buf, "NAME%d",i);
    names[i] = strdup(buf);
  }

  /* do tests */
  double start, XlibTime, XlibGoodTime, XCBBadTime, XCBGoodTime;

  /* test Xlib */
  Display *display = XOpenDisplay(NULL);
  start = get_time();
  useXlib(names, display);
  XlibTime = get_time() - start;
  start = get_time();
  useXlibProperly(names, display);
  XlibGoodTime = get_time() -start;
  XCloseDisplay(display);

  /* test XCB */
  xcb_connection_t *connection = xcb_connect(NULL,NULL);
  start = get_time();
  useXCBPoorly(names, connection);
  XCBBadTime = get_time() - start;
  start = get_time();
  useXCBProperly(names, connection);
  XCBGoodTime = get_time() - start;
  xcb_disconnect(connection);

  /* report times */
  printf("Bad Xlib time: %f\n", XlibTime);
  printf("Good Xlib time: %f\n",XlibGoodTime);
  printf("Bad xcb time: %f\n",XCBBadTime);
  printf("Good xcb time: %f\n",XCBGoodTime);
  printf("ratio of good xcb time to bad xcb time: %f\n",XCBGoodTime / XCBBadTime);
  printf("ratio of Xlib time to good xcb time: %f\n",XlibTime / XCBGoodTime);
  printf("ratio of good time to bad Xlib time: %f\n",XlibGoodTime / XlibTime);

  return 0;
}
