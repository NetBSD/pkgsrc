$NetBSD: patch-mozilla_config_system__wrappers_unwind.h,v 1.9 2015/12/03 12:22:27 ryoon Exp $

--- mozilla/config/system_wrappers/unwind.h.orig	2015-12-02 14:51:45.000000000 +0000
+++ mozilla/config/system_wrappers/unwind.h
@@ -0,0 +1,4 @@
+#pragma GCC system_header
+#pragma GCC visibility push(default)
+#include_next <unwind.h>
+#pragma GCC visibility pop
