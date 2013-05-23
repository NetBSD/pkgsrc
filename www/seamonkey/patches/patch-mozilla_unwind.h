$NetBSD: patch-mozilla_unwind.h,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/unwind.h.orig	2013-05-21 12:42:41.000000000 +0000
+++ mozilla/unwind.h
@@ -0,0 +1,4 @@
+#pragma GCC system_header
+#pragma GCC visibility push(default)
+#include_next <unwind.h>
+#pragma GCC visibility pop
