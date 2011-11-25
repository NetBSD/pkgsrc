$NetBSD: patch-src_FbDesk.cc,v 1.1 2011/11/25 22:25:31 joerg Exp $

--- src/FbDesk.cc.orig	2011-11-25 17:43:42.000000000 +0000
+++ src/FbDesk.cc
@@ -39,6 +39,7 @@
 #include <algorithm>
 #include <unistd.h>
 #include <cstdio>
+#include <cstring>
 
 using namespace std;
 using namespace FbTk;
