$NetBSD: patch-src_unix_fswatcher__kqueue.cpp,v 1.1 2014/08/13 22:32:43 joerg Exp $

--- src/unix/fswatcher_kqueue.cpp.orig	2014-08-13 21:20:42.000000000 +0000
+++ src/unix/fswatcher_kqueue.cpp
@@ -125,8 +125,13 @@ public:
         struct kevent event;
         int action = EV_ADD | EV_ENABLE | EV_CLEAR | EV_ERROR;
         int flags = Watcher2NativeFlags(watch->GetFlags());
+#ifdef __NetBSD__
+        EV_SET( &event, watch->GetFileDescriptor(), EVFILT_VNODE, action,
+                flags, 0, (intptr_t)watch.get() );
+#else
         EV_SET( &event, watch->GetFileDescriptor(), EVFILT_VNODE, action,
                 flags, 0, watch.get() );
+#endif
 
         // TODO more error conditions according to man
         // TODO best deal with the error here
@@ -281,10 +286,11 @@ protected:
 
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
