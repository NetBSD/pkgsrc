$NetBSD: patch-mozilla_ipc_chromium_src_base_scoped__nsautorelease__pool.h,v 1.1 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/ipc/chromium/src/base/scoped_nsautorelease_pool.h.orig	2014-06-13 00:45:30.000000000 +0000
+++ mozilla/ipc/chromium/src/base/scoped_nsautorelease_pool.h
@@ -7,13 +7,13 @@
 
 #include "base/basictypes.h"
 
-#if defined(OS_MACOSX)
+#if defined(MOZ_WIDGET_COCOA)
 #if defined(__OBJC__)
 @class NSAutoreleasePool;
 #else  // __OBJC__
 class NSAutoreleasePool;
 #endif  // __OBJC__
-#endif  // OS_MACOSX
+#endif  // MOZ_WIDGET_COCOA
 
 namespace base {
 
@@ -27,10 +27,10 @@ namespace base {
 // ugly #ifdefs.
 class ScopedNSAutoreleasePool {
  public:
-#if !defined(OS_MACOSX)
+#if !defined(MOZ_WIDGET_COCOA)
   ScopedNSAutoreleasePool() {}
   void Recycle() { }
-#else  // OS_MACOSX
+#else  // MOZ_WIDGET_COCOA
   ScopedNSAutoreleasePool();
   ~ScopedNSAutoreleasePool();
 
@@ -41,7 +41,7 @@ class ScopedNSAutoreleasePool {
   void Recycle();
  private:
   NSAutoreleasePool* autorelease_pool_;
-#endif  // OS_MACOSX
+#endif  // MOZ_WIDGET_COCOA
 
  private:
   DISALLOW_COPY_AND_ASSIGN(ScopedNSAutoreleasePool);
