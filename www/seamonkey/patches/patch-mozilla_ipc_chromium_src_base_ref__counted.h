$NetBSD: patch-mozilla_ipc_chromium_src_base_ref__counted.h,v 1.1 2012/09/06 12:08:51 ryoon Exp $

--- mozilla/ipc/chromium/src/base/ref_counted.h.orig	2012-08-27 04:49:15.000000000 +0000
+++ mozilla/ipc/chromium/src/base/ref_counted.h
@@ -28,7 +28,7 @@ class RefCountedBase {
   bool in_dtor_;
 #endif
 
-  DFAKE_MUTEX(add_release_);
+  DFAKE_MUTEX(add_release_)
 
   DISALLOW_COPY_AND_ASSIGN(RefCountedBase);
 };
