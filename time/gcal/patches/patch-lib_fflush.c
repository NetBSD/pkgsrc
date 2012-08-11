$NetBSD: patch-lib_fflush.c,v 1.2 2012/08/11 18:51:16 ryoon Exp $

--- lib/fflush.c.orig	2012-04-06 15:05:23.000000000 +0000
+++ lib/fflush.c
@@ -94,7 +94,7 @@ update_fpos_cache (FILE *fp _GL_UNUSED_P
                    off_t pos _GL_UNUSED_PARAMETER)
 {
 #if defined __sferror || defined __DragonFly__ /* FreeBSD, NetBSD, OpenBSD, DragonFly, MacOS X, Cygwin */
-# if defined __CYGWIN__
+# if defined(__CYGWIN__) || defined(__NetBSD__)
   /* fp_->_offset is typed as an integer.  */
   fp_->_offset = pos;
 # else
