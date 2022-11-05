$NetBSD: patch-xtrlock.c,v 1.1 2022/11/05 18:18:13 pin Exp $

Portability fixes for BSD systems.

--- xtrlock.c.orig	2021-02-13 15:34:52.000000000 +0000
+++ xtrlock.c
@@ -31,11 +31,16 @@
 #include <grp.h>
 #include <limits.h>
 #include <string.h>
+#include <sys/param.h>
+#ifndef BSD
 #include <crypt.h>
+#endif
 #include <unistd.h>
 #include <math.h>
 #include <ctype.h>
+#ifndef BSD
 #include <values.h>
+#endif
 
 #ifdef SHADOW_PWD
 #include <shadow.h>
@@ -138,8 +143,12 @@ int main(int argc, char **argv){
       exit(1);
     }
   }
-  
+
+#ifdef __OpenBSD__
+  errno=0;  pw= getpwuid_shadow(getuid());
+#else
   errno=0;  pw= getpwuid(getuid());
+#endif
   if (!pw) { perror("password entry for uid not found"); exit(1); }
 #ifdef SHADOW_PWD
   sp = getspnam(pw->pw_name);
