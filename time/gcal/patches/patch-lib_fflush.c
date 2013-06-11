$NetBSD: patch-lib_fflush.c,v 1.3 2013/06/11 11:54:47 ryoon Exp $

* Support fpos_t change.

--- lib/fflush.c.orig	2013-01-19 12:35:32.000000000 +0000
+++ lib/fflush.c
@@ -96,7 +96,7 @@ update_fpos_cache (FILE *fp _GL_UNUSED_P
                    off_t pos _GL_UNUSED_PARAMETER)
 {
 #  if defined __sferror || defined __DragonFly__ /* FreeBSD, NetBSD, OpenBSD, DragonFly, Mac OS X, Cygwin */
-#   if defined __CYGWIN__
+#   if defined(__CYGWIN__) || defined(__NetBSD__)
   /* fp_->_offset is typed as an integer.  */
   fp_->_offset = pos;
 #   else
