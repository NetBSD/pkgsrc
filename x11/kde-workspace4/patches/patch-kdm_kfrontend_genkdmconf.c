$NetBSD: patch-kdm_kfrontend_genkdmconf.c,v 1.2 2015/01/15 17:59:10 rumko Exp $

On some systems (e.g. fbsd 10+) utmp is no longer available, use utmpx instead.

--- kdm/kfrontend/genkdmconf.c.orig	2014-11-06 22:36:58.000000000 +0000
+++ kdm/kfrontend/genkdmconf.c
@@ -46,12 +46,18 @@ Foundation, Inc., 51 Franklin Street, Fi
 #include <sys/wait.h>
 #include <sys/param.h>
 #ifdef BSD
-# ifdef BSD_UTMP
+# ifdef HAVE_UTMPX
+#  include <utmpx.h>
+# else
 #  include <utmp.h>
 # endif
 # ifndef _PATH_UTMP
 #  if defined(__FreeBSD_version) && __FreeBSD_version >= 900007
-#   define _PATH_UTMP "/var/run/utmp"
+#   if __FreeBSD_version >= 1001000
+#    define _PATH_UTMP "/var/run/utx.active"
+#   else
+#    define _PATH_UTMP "/var/run/utmp"
+#   endif
 #  else
 #   error "_PATH_UTMP must be defined"
 #  endif
