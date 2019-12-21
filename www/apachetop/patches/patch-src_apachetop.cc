$NetBSD: patch-src_apachetop.cc,v 1.1 2019/12/21 23:51:30 joerg Exp $

--- src/apachetop.cc.orig	2019-12-21 18:35:00.053790104 +0000
+++ src/apachetop.cc
@@ -4,6 +4,10 @@
 */
 #include "apachetop.h"
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#endif
+
 /* die and report why */
 #define DIE(msg) fprintf(stderr, "%s: %s\n", msg, strerror(errno)); catchsig(1);
 /* die with no strerror */
@@ -1023,7 +1027,7 @@ int new_file(const char *filename, bool 
 
 #if (POLLING_METHOD == USING_KQUEUE)
 	/* add into kqueue */
-#ifdef __NetBSD__
+#if defined(__NetBSD__) && (__NetBSD_Version__ - 0 < 999001500)
 	EV_SET(&kev, fd, EVFILT_VNODE,
 	    EV_ADD | EV_ENABLE | EV_CLEAR,
 	    NOTE_WRITE | NOTE_DELETE | NOTE_RENAME, 0, (intptr_t)this_file);
