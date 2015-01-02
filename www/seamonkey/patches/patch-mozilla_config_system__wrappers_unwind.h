$NetBSD: patch-mozilla_config_system__wrappers_unwind.h,v 1.5 2015/01/02 04:26:21 ryoon Exp $

--- mozilla/config/system_wrappers/unwind.h.orig	2015-01-01 17:44:51.000000000 +0000
+++ mozilla/config/system_wrappers/unwind.h
@@ -0,0 +1,4 @@
+#pragma GCC system_header
+#pragma GCC visibility push(default)
+#include_next <unwind.h>
+#pragma GCC visibility pop
