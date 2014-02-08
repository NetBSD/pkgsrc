$NetBSD: patch-config_system__wrappers_unwind.h,v 1.4 2014/02/08 09:36:00 ryoon Exp $

--- config/system_wrappers/unwind.h.orig	2014-02-08 06:57:27.000000000 +0000
+++ config/system_wrappers/unwind.h
@@ -0,0 +1,4 @@
+#pragma GCC system_header
+#pragma GCC visibility push(default)
+#include_next <unwind.h>
+#pragma GCC visibility pop
