$NetBSD: patch-kdm_kfrontend_genkdmconf.c,v 1.3 2015/01/25 13:15:34 joerg Exp $

Use utmpx on all BSDs.

--- kdm/kfrontend/genkdmconf.c.orig	2014-11-06 22:36:58.000000000 +0000
+++ kdm/kfrontend/genkdmconf.c
@@ -46,16 +46,7 @@ Foundation, Inc., 51 Franklin Street, Fi
 #include <sys/wait.h>
 #include <sys/param.h>
 #ifdef BSD
-# ifdef BSD_UTMP
-#  include <utmp.h>
-# endif
-# ifndef _PATH_UTMP
-#  if defined(__FreeBSD_version) && __FreeBSD_version >= 900007
-#   define _PATH_UTMP "/var/run/utmp"
-#  else
-#   error "_PATH_UTMP must be defined"
-#  endif
-# endif
+#  include <utmpx.h>
 #endif
 
 #define WANT_CONF_GEN
@@ -1875,7 +1866,7 @@ edit_startup(File *file)
 #else
 # ifdef BSD
             delstr(file, "\n"
-"exec sessreg -a -l $DISPLAY -x */Xservers -u " _PATH_UTMP " $USER\n") |
+"exec sessreg -a -l $DISPLAY -x */Xservers -u " _PATH_UTMPX " $USER\n") |
 # endif
 #endif /* _AIX */
             delstr(file, "\n"
@@ -1924,7 +1915,7 @@ edit_reset(File *file)
 #else
 # ifdef BSD
         delstr(file, "\n"
-"exec sessreg -d -l $DISPLAY -x */Xservers -u " _PATH_UTMP " $USER\n") |
+"exec sessreg -d -l $DISPLAY -x */Xservers -u " _PATH_UTMPX " $USER\n") |
 # endif
 #endif /* _AIX */
         delstr(file, "\n"
