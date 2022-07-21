$NetBSD: patch-widget_gtk_DMABufSurface.cpp,v 1.1 2022/07/21 23:56:39 nia Exp $

No eventfd on netbsd, fix build

--- widget/gtk/DMABufSurface.cpp.orig	2021-04-08 21:20:12.000000000 +0000
+++ widget/gtk/DMABufSurface.cpp
@@ -18,7 +18,9 @@
 #include <sys/time.h>
 #include <dlfcn.h>
 #include <sys/mman.h>
+#ifndef __NetBSD__
 #include <sys/eventfd.h>
+#endif
 #include <poll.h>
 #include <sys/ioctl.h>
 
@@ -97,6 +99,7 @@ void DMABufSurface::GlobalRefAdd() {
 }
 
 void DMABufSurface::GlobalRefCountCreate() {
+#ifndef __NetBSD__
   MOZ_ASSERT(!mGlobalRefCountFd);
   mGlobalRefCountFd = eventfd(0, EFD_CLOEXEC | EFD_NONBLOCK | EFD_SEMAPHORE);
   if (mGlobalRefCountFd < 0) {
@@ -106,6 +109,7 @@ void DMABufSurface::GlobalRefCountCreate
     mGlobalRefCountFd = 0;
     return;
   }
+#endif
 }
 
 void DMABufSurface::GlobalRefCountImport(int aFd) {
