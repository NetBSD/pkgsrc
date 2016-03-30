$NetBSD: patch-mozilla_config_system__wrappers_unwind.h,v 1.11 2016/03/30 12:56:53 ryoon Exp $

--- mozilla/config/system_wrappers/unwind.h.orig	2016-03-29 13:09:26.670237158 +0000
+++ mozilla/config/system_wrappers/unwind.h
@@ -0,0 +1,4 @@
+#pragma GCC system_header
+#pragma GCC visibility push(default)
+#include_next <unwind.h>
+#pragma GCC visibility pop
