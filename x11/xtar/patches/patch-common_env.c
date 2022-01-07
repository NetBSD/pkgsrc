$NetBSD: patch-common_env.c,v 1.1 2022/01/07 13:02:31 nia Exp $

- Fix implicit declaration warnings.

--- common/env.c.orig	1995-05-09 08:06:46.000000000 +0000
+++ common/env.c
@@ -27,6 +27,7 @@
 #include <sys/param.h>
 #include <sys/utsname.h>
 
+#include "file.h"
 #include "env.h"
 
 int env_osrelease();
