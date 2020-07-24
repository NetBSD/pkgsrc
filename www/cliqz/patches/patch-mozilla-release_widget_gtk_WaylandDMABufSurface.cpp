$NetBSD: patch-mozilla-release_widget_gtk_WaylandDMABufSurface.cpp,v 1.1 2020/07/24 07:29:32 fox Exp $

* Fix build under NetBSD.

Taken from www/firefox

--- mozilla-release/widget/gtk/WaylandDMABufSurface.cpp.orig	2020-06-19 02:17:05.000000000 +0000
+++ mozilla-release/widget/gtk/WaylandDMABufSurface.cpp
@@ -18,7 +18,9 @@
 #include <sys/time.h>
 #include <dlfcn.h>
 #include <sys/mman.h>
+#if !defined(__NetBSD__)
 #include <sys/eventfd.h>
+#endif
 #include <poll.h>
 
 #include "mozilla/widget/gbm.h"
@@ -91,6 +93,7 @@ void WaylandDMABufSurface::GlobalRefAdd(
 }
 
 void WaylandDMABufSurface::GlobalRefCountCreate() {
+#if !defined(__NetBSD__)
   MOZ_ASSERT(!mGlobalRefCountFd);
   mGlobalRefCountFd = eventfd(0, EFD_CLOEXEC | EFD_NONBLOCK | EFD_SEMAPHORE);
   if (mGlobalRefCountFd < 0) {
@@ -98,6 +101,7 @@ void WaylandDMABufSurface::GlobalRefCoun
     mGlobalRefCountFd = 0;
     return;
   }
+#endif
 }
 
 void WaylandDMABufSurface::GlobalRefCountImport(int aFd) {
