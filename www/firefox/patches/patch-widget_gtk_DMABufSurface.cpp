$NetBSD: patch-widget_gtk_DMABufSurface.cpp,v 1.4 2023/04/05 14:22:36 ryoon Exp $

No eventfd on NetBSD 9 and older, fix build

--- widget/gtk/DMABufSurface.cpp.orig	2023-03-02 21:15:57.000000000 +0000
+++ widget/gtk/DMABufSurface.cpp
@@ -6,6 +6,9 @@
 
 #include "DMABufSurface.h"
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#endif
 #include <fcntl.h>
 #include <getopt.h>
 #include <signal.h>
@@ -18,7 +21,9 @@
 #include <sys/time.h>
 #include <dlfcn.h>
 #include <sys/mman.h>
+#if !(defined(__NetBSD__) && (__NetBSD_Version__ - 0 < 1000000000))
 #include <sys/eventfd.h>
+#endif
 #include <poll.h>
 #include <sys/ioctl.h>
 
@@ -128,6 +133,7 @@ void DMABufSurface::GlobalRefAdd() {
 }
 
 void DMABufSurface::GlobalRefCountCreate() {
+#if !(defined(__NetBSD__) && (__NetBSD_Version__ - 0 < 1000000000))
   MOZ_ASSERT(!mGlobalRefCountFd);
   mGlobalRefCountFd = eventfd(0, EFD_CLOEXEC | EFD_NONBLOCK | EFD_SEMAPHORE);
   if (mGlobalRefCountFd < 0) {
@@ -137,6 +143,7 @@ void DMABufSurface::GlobalRefCountCreate
     mGlobalRefCountFd = 0;
     return;
   }
+#endif
 }
 
 void DMABufSurface::GlobalRefCountImport(int aFd) {
