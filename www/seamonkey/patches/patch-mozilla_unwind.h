$NetBSD: patch-mozilla_unwind.h,v 1.7 2017/08/18 23:55:07 ryoon Exp $

--- mozilla/unwind.h.orig	2017-08-18 14:25:23.038713577 +0000
+++ mozilla/unwind.h
@@ -0,0 +1,4 @@
+#pragma GCC system_header
+#pragma GCC visibility push(default)
+#include_next <unwind.h>
+#pragma GCC visibility pop
