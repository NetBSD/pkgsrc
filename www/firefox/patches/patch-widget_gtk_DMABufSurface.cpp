$NetBSD: patch-widget_gtk_DMABufSurface.cpp,v 1.5 2023/04/18 14:00:11 ryoon Exp $

No eventfd on NetBSD 9 and older, fix build

--- widget/gtk/DMABufSurface.cpp.orig	2023-03-30 21:16:10.000000000 +0000
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
 
@@ -134,6 +139,7 @@ void DMABufSurface::GlobalRefAdd() {
 }
 
 void DMABufSurface::GlobalRefCountCreate() {
+#if !(defined(__NetBSD__) && (__NetBSD_Version__ - 0 < 1000000000))
   MOZ_ASSERT(!mGlobalRefCountFd);
   // Create global ref count initialized to 0,
   // i.e. is not referenced after create.
@@ -145,6 +151,7 @@ void DMABufSurface::GlobalRefCountCreate
     mGlobalRefCountFd = 0;
     return;
   }
+#endif
 }
 
 void DMABufSurface::GlobalRefCountImport(int aFd) {
