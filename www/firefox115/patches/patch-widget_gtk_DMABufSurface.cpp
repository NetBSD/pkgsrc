$NetBSD: patch-widget_gtk_DMABufSurface.cpp,v 1.1 2023/09/11 12:33:25 ryoon Exp $

No eventfd on NetBSD 9 and older, fix build

--- widget/gtk/DMABufSurface.cpp.orig	2023-06-22 21:19:23.000000000 +0000
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
 
@@ -147,6 +152,7 @@ void DMABufSurface::GlobalRefAdd() {
 }
 
 void DMABufSurface::GlobalRefCountCreate() {
+#if !(defined(__NetBSD__) && (__NetBSD_Version__ - 0 < 1000000000))
   LOGDMABUFREF(("DMABufSurface::GlobalRefCountCreate UID %d", mUID));
   MOZ_DIAGNOSTIC_ASSERT(!mGlobalRefCountFd);
   // Create global ref count initialized to 0,
@@ -159,6 +165,7 @@ void DMABufSurface::GlobalRefCountCreate
     mGlobalRefCountFd = 0;
     return;
   }
+#endif
 }
 
 void DMABufSurface::GlobalRefCountImport(int aFd) {
