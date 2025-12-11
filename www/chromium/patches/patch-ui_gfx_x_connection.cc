$NetBSD: patch-ui_gfx_x_connection.cc,v 1.1 2025/12/11 09:13:47 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/x/connection.cc.orig	2025-11-19 21:40:05.000000000 +0000
+++ ui/gfx/x/connection.cc
@@ -410,7 +410,7 @@ bool Connection::HasNextEvent() {
     }
     events_.pop_front();
   }
-#if BUILDFLAG(IS_LINUX)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_BSD)
   // Move an event from XCB's internal queue to our queue, if available.
   return ReadResponse(/*queued=*/false);
 #else
