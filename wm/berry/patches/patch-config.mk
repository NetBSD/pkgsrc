$NetBSD: patch-config.mk,v 1.1 2020/12/05 13:13:43 nia Exp $

Respect CFLAGS/LDFLAGS.

--- config.mk.orig	2020-11-02 17:22:47.000000000 +0000
+++ config.mk
@@ -36,8 +36,8 @@ LIBS = -L${X11LIB} -lX11 ${XINERAMALIBS}
 # flags
 CPPFLAGS = -D_DEFAULT_SOURCE -D_BSD_SOURCE -D_POSIX_C_SOURCE=2 -DVERSION=\"${VERSION}\" ${XINERAMAFLAGS} ${DEBUG_CPPFLAGS}
 #CFLAGS   = -g -std=c99 -pedantic -Wall -O0 ${INCS} ${CPPFLAGS} ${DEBUG_CFLAGS}
-CFLAGS   = -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os ${INCS} ${CPPFLAGS} ${DEBUG_CFLAGS} $(NAME_DEFINES)
-LDFLAGS  = ${LIBS}
+CFLAGS  += -std=c99 -pedantic -Wall -Wno-deprecated-declarations -Os ${INCS} ${CPPFLAGS} ${DEBUG_CFLAGS} $(NAME_DEFINES)
+LDFLAGS += ${LIBS}
 
 # Solaris
 #CFLAGS  = -fast ${INCS} -DVERSION=\"${VERSION}\"
