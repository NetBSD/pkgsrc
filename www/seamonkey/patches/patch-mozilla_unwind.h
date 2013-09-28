$NetBSD: patch-mozilla_unwind.h,v 1.3 2013/09/28 14:37:05 ryoon Exp $

--- mozilla/unwind.h.orig	2013-09-28 01:07:15.000000000 +0000
+++ mozilla/unwind.h
@@ -0,0 +1,4 @@
+#pragma GCC system_header
+#pragma GCC visibility push(default)
+#include_next <unwind.h>
+#pragma GCC visibility pop
