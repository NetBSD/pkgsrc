$NetBSD: patch-src_base_TidyPointer.h,v 1.2 2015/05/29 07:50:59 adam Exp $

Define NULL if not defined.

--- src/base/TidyPointer.h.orig	2015-05-28 11:06:38.000000000 +0000
+++ src/base/TidyPointer.h
@@ -9,6 +9,10 @@
 #ifndef SQUID_BASE_TIDYPOINTER_H
 #define SQUID_BASE_TIDYPOINTER_H
 
+#ifndef NULL
+#define NULL ((void *)0)
+#endif
+
 /**
  * A pointer that deletes the object it points to when the pointer's owner or
  * context is gone. Similar to std::unique_ptr but without confusing assignment
