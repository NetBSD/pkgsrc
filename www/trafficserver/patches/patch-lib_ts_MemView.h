$NetBSD: patch-lib_ts_MemView.h,v 1.1 2017/08/17 14:57:09 fhajny Exp $

--- lib/ts/MemView.h.orig	2017-07-18 06:25:04.000000000 +0000
+++ lib/ts/MemView.h
@@ -33,6 +33,7 @@
 #include <memory.h>
 #include <algorithm>
 #include <string>
+#include <cstring>
 
 /// Apache Traffic Server commons.
 namespace ts
