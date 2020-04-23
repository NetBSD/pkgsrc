$NetBSD: patch-lib_kpty__p.h,v 1.1 2020/04/23 04:11:19 gutteridge Exp $

Fix macOS build.

--- lib/kpty_p.h.orig	2019-02-25 22:13:12.000000000 +0000
+++ lib/kpty_p.h
@@ -35,9 +35,7 @@ public:
     KPtyPrivate(KPty* parent);
     virtual ~KPtyPrivate();
 
-#ifndef HAVE_OPENPTY
     bool chownpty(bool grant);
-#endif
 
     int masterFd;
     int slaveFd;
