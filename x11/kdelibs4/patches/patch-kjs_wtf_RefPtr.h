$NetBSD: patch-kjs_wtf_RefPtr.h,v 1.1 2012/01/23 08:14:02 joerg Exp $

--- kjs/wtf/RefPtr.h.orig	2012-01-22 20:08:54.000000000 +0000
+++ kjs/wtf/RefPtr.h
@@ -24,6 +24,7 @@
 
 #include <algorithm>
 #include "AlwaysInline.h"
+#include "PassRefPtr.h"
 
 namespace WTF {
 
