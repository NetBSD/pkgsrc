$NetBSD: patch-common_magic.h,v 1.1 2022/01/07 12:43:14 nia Exp $

- Add support for bzip2 and xz archives.

--- common/magic.h.orig	1995-05-09 08:06:46.000000000 +0000
+++ common/magic.h
@@ -27,13 +27,15 @@
 #define	MAGIC_GZIP		4
 #define	MAGIC_TROFF		5
 #define	MAGIC_POSTSCRIPT	6
+#define	MAGIC_BZIP2		7
+#define	MAGIC_XZ		8
 
 extern int magic_ftype(char *, int);
 
 #define	is_jpeg(filename)	magic_ftype(filename, MAGIC_JPEG)
 #define	is_gif(filename)	magic_ftype(filename, MAGIC_GIF)
 #define	is_compressed(filename)	magic_ftype(filename, MAGIC_COMPRESS)
-#define	is_gzipped(filename)	magic_ftype(filename, MAGIC_GZIP)
+#define	is_gzipped(filename)	magic_ftype(filename, MAGIC_GZIP) || magic_ftype(filename, MAGIC_BZIP2) || magic_ftype(filename, MAGIC_XZ)
 #define	is_troff(filename)	magic_ftype(filename, MAGIC_TROFF)
 #define	is_postscript(filename)	magic_ftype(filename, MAGIC_POSTSCRIPT)
 
