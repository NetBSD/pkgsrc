$NetBSD: patch-src_cxx__supportlib_Hooks.h,v 1.1 2018/01/30 15:42:02 fhajny Exp $

WEXITSTATUS()

--- src/cxx_supportlib/Hooks.h.orig	2013-10-27 00:00:00.000000000 +0000
+++ src/cxx_supportlib/Hooks.h
@@ -38,6 +38,7 @@
 #include <cstring>
 #include <cctype>
 #include <stdlib.h>
+#include <sys/wait.h>
 
 #include <jsoncpp/json.h>
 
