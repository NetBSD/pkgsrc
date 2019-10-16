$NetBSD: patch-src_unix_fswatcher__kqueue.cpp,v 1.3 2019/10/16 20:43:14 wiz Exp $

Fix compilation error on NetBSD
https://trac.wxwidgets.org/ticket/18199

--- src/unix/fswatcher_kqueue.cpp.orig	2018-03-07 16:55:38.000000000 +0000
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
@@ -125,8 +129,13 @@ public:
         struct kevent event;
         int action = EV_ADD | EV_ENABLE | EV_CLEAR | EV_ERROR;
         int flags = Watcher2NativeFlags(watch->GetFlags());
+#if defined(__NetBSD__) && (__NetBSD_Version__ <= 999001400)
+        EV_SET( &event, watch->GetFileDescriptor(), EVFILT_VNODE, action,
+                flags, 0, (intptr_t)watch.get() );
+#else
         EV_SET( &event, watch->GetFileDescriptor(), EVFILT_VNODE, action,
                 flags, 0, watch.get() );
+#endif
 
         // TODO more error conditions according to man
         // TODO best deal with the error here
@@ -281,10 +290,11 @@ protected:
 
         wxLogTrace(wxTRACE_FSWATCHER, "Event: ident=%d, filter=%d, flags=%u, "
                    "fflags=%u, data=%d, user_data=%p",
-                   e.ident, e.filter, e.flags, e.fflags, e.data, e.udata);
+                   e.ident, e.filter, e.flags, e.fflags, e.data,
+                   (const void *)e.udata);
 
         // for ease of use
-        wxFSWatchEntryKq& w = *(static_cast<wxFSWatchEntry*>(e.udata));
+        wxFSWatchEntryKq& w = *(reinterpret_cast<wxFSWatchEntry*>(e.udata));
         int nflags = e.fflags;
 
         // clear ignored flags
