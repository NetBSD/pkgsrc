$NetBSD: patch-widget_gtk_DMABufSurface.cpp,v 1.1 2020/07/31 01:26:43 maya Exp $

No eventfd on netbsd, fix build

--- widget/gtk/DMABufSurface.cpp.orig	2020-07-20 20:56:52.000000000 +0000
+++ widget/gtk/DMABufSurface.cpp
@@ -18,7 +18,9 @@
 #include <sys/time.h>
 #include <dlfcn.h>
 #include <sys/mman.h>
+#ifndef __NetBSD__
 #include <sys/eventfd.h>
+#endif
 #include <poll.h>
 
 #include "mozilla/widget/gbm.h"
@@ -91,6 +93,7 @@ void DMABufSurface::GlobalRefAdd() {
 }
 
 void DMABufSurface::GlobalRefCountCreate() {
+#ifndef __NetBSD__
   MOZ_ASSERT(!mGlobalRefCountFd);
   mGlobalRefCountFd = eventfd(0, EFD_CLOEXEC | EFD_NONBLOCK | EFD_SEMAPHORE);
   if (mGlobalRefCountFd < 0) {
@@ -98,6 +101,7 @@ void DMABufSurface::GlobalRefCountCreate
     mGlobalRefCountFd = 0;
     return;
   }
+#endif
 }
 
 void DMABufSurface::GlobalRefCountImport(int aFd) {
