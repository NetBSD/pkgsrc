$NetBSD: patch-ui_gfx_x_generated__protos_shm.cc,v 1.15 2026/02/15 09:04:14 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/x/generated_protos/shm.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ ui/gfx/x/generated_protos/shm.cc
@@ -27,6 +27,8 @@
 #include <xcb/xcb.h>
 #include <xcb/xcbext.h>
 
+#include <unistd.h>
+
 #include "base/logging.h"
 #include "base/posix/eintr_wrapper.h"
 #include "ui/gfx/x/connection.h"
