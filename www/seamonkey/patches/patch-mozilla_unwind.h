$NetBSD: patch-mozilla_unwind.h,v 1.5 2014/11/02 05:40:31 ryoon Exp $

--- mozilla/unwind.h.orig	2014-11-01 10:20:11.000000000 +0000
+++ mozilla/unwind.h
@@ -0,0 +1,4 @@
+#pragma GCC system_header
+#pragma GCC visibility push(default)
+#include_next <unwind.h>
+#pragma GCC visibility pop
