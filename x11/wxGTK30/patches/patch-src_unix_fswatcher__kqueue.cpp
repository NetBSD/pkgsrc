$NetBSD: patch-src_unix_fswatcher__kqueue.cpp,v 1.4 2020/07/18 13:02:54 adam Exp $

Fix compilation error on NetBSD
https://trac.wxwidgets.org/ticket/18199

--- src/unix/fswatcher_kqueue.cpp.orig	2020-07-18 06:20:35.185180562 +0000
+++ src/unix/fswatcher_kqueue.cpp
@@ -14,6 +14,10 @@
     #pragma hdrstop
 #endif
 
+#ifdef __NetBSD__
+#include <sys/param.h>
+#endif
+
 #if wxUSE_FSWATCHER
 
 #include "wx/fswatcher.h"
@@ -34,7 +38,7 @@ namespace
 
 // NetBSD is different as it uses intptr_t as type of kevent struct udata field
 // for some reason, instead of "void*" as all the other platforms using kqueue.
-#ifdef __NetBSD__
+#if defined(__NetBSD__) && (__NetBSD_Version__ <= 999001400)
     inline intptr_t ToUdata(void* d) { return reinterpret_cast<intptr_t>(d); }
     inline void* FromUdata(intptr_t d) { return reinterpret_cast<void*>(d); }
 #else
