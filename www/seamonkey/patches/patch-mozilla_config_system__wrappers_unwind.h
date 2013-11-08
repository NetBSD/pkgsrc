$NetBSD: patch-mozilla_config_system__wrappers_unwind.h,v 1.3 2013/11/08 12:55:52 ryoon Exp $

--- mozilla/config/system_wrappers/unwind.h.orig	2013-11-04 05:52:46.000000000 +0000
+++ mozilla/config/system_wrappers/unwind.h
@@ -0,0 +1,4 @@
+#pragma GCC system_header
+#pragma GCC visibility push(default)
+#include_next <unwind.h>
+#pragma GCC visibility pop
