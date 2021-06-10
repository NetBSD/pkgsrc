$NetBSD: patch-src_main.cc,v 1.1 2021/06/10 12:48:50 nia Exp $

Uses LC_ALL.

--- src/main.cc.orig	2018-12-26 00:36:20.419139718 +0000
+++ src/main.cc
@@ -36,7 +36,7 @@
 #include "version.h"
 
 #include <cstdio>
-
+#include <clocale>
 #include <cstring>
 
 
