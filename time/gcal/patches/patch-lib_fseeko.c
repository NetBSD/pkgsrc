$NetBSD: patch-lib_fseeko.c,v 1.3 2013/06/11 11:54:47 ryoon Exp $

* Support fpos_t change.

--- lib/fseeko.c.orig	2013-03-29 20:35:20.000000000 +0000
+++ lib/fseeko.c
@@ -121,7 +121,7 @@ fseeko (FILE *fp, off_t offset, int when
       fp->_flags &= ~_IO_EOF_SEEN;
       fp->_offset = pos;
 #elif defined __sferror || defined __DragonFly__ /* FreeBSD, NetBSD, OpenBSD, DragonFly, Mac OS X, Cygwin */
-# if defined __CYGWIN__
+# if defined(__CYGWIN__) || defined(__NetBSD__)
       /* fp_->_offset is typed as an integer.  */
       fp_->_offset = pos;
 # else
