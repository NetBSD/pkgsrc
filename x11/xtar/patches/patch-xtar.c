$NetBSD: patch-xtar.c,v 1.1 2022/01/07 12:43:14 nia Exp $

- Fix implicit declaration warnings.
- Remove an unused variable that assumes it knows the size of
  a private struct.

--- xtar.c.orig	1995-07-17 11:44:19.000000000 +0000
+++ xtar.c
@@ -31,6 +31,7 @@
 #include <sys/param.h>
 #include <sys/wait.h>
 #include <sys/stat.h>
+#include <stdlib.h>
 #include <string.h>
 #include <unistd.h>
 
@@ -46,6 +47,7 @@
 #include <Xm/ScrolledW.h>
 #include <Xm/Text.h>
 #include <Xm/TextF.h>
+#include <Xm/ToggleB.h>
 
 #include "Xbr.h"
 #include "xtarint.h"
@@ -1164,7 +1166,6 @@ static int xtar_show(char *tfname, char 
 static int xtar_attributes(TAR_FILE *tf, char *filename)
 {
     int retval = 0;
-    struct utimbuf utimbuf;
 
     /* If the file type is not a directory then try and set the access
        permissions. We exclude directories because if write permission
