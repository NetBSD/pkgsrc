$NetBSD: patch-ksysguard_ksysguardd_Solaris_LoadAvg.c,v 1.1 2013/06/22 22:39:10 jperkin Exp $

Need string.h

--- ksysguard/ksysguardd/Solaris/LoadAvg.c.orig	2013-05-03 04:36:45.431119797 +0000
+++ ksysguard/ksysguardd/Solaris/LoadAvg.c
@@ -22,6 +22,7 @@
 
 #include <stdio.h>
 #include <stdlib.h>
+#include <string.h>
 #include <unistd.h>
 #include <sys/stat.h>
 #include <sys/types.h>
