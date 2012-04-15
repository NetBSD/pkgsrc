$NetBSD: patch-kdm_kfrontend_genkdmconf.c,v 1.1 2012/04/15 05:55:00 markd Exp $

--- kdm/kfrontend/genkdmconf.c.orig	2012-03-29 22:02:31.000000000 +0000
+++ kdm/kfrontend/genkdmconf.c
@@ -46,9 +46,7 @@ Foundation, Inc., 51 Franklin Street, Fi
 #include <sys/wait.h>
 #include <sys/param.h>
 #ifdef BSD
-# ifdef BSD_UTMP
 #  include <utmp.h>
-# endif
 # ifndef _PATH_UTMP
 #  if defined(__FreeBSD_version) && __FreeBSD_version >= 900007
 #   define _PATH_UTMP "/var/run/utmp"
