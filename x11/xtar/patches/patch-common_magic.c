$NetBSD: patch-common_magic.c,v 1.1 2022/01/07 12:43:14 nia Exp $

- Fix implicit declaration warnings.
- Add support for bzip2 and xz archives.

--- common/magic.c.orig	1995-05-09 08:06:46.000000000 +0000
+++ common/magic.c
@@ -21,6 +21,8 @@
 
 #include <fcntl.h>
 #include <stdio.h>
+#include <string.h>
+#include <unistd.h>
 
 #include "magic.h"
 
@@ -30,6 +32,8 @@ static unsigned char jpeg[2]       = { 0
 static unsigned char gif[3]        = { 0x47, 0x49, 0x46 };
 static unsigned char compress[3]   = { 0x1f, 0x9d, 0x90 };
 static unsigned char gzip[3]       = { 0x1f, 0x8b, 0x08 };
+static unsigned char bzip2[3]      = { 0x42, 0x5a, 0x68 };
+static unsigned char xz[3]         = { 0xfd, 0x37, 0x7a };
 static unsigned char troff[2]      = { 0x5c, 0x22 };
 static unsigned char postscript[2] = { 0x25, 0x21 };
 
@@ -65,6 +69,14 @@ int magic_ftype(char *filename, int type
 
     /* Compare bytes with type we are after */
     switch(type) { 
+        case MAGIC_BZIP2:
+            if(!memcmp(buffer, bzip2, 3))
+                return(1); 
+            break;
+        case MAGIC_XZ:
+            if(!memcmp(buffer, xz, 3))
+                return(1); 
+            break;
         case MAGIC_JPEG:
             if(!memcmp(buffer, jpeg, 2))
                 return(1); 
