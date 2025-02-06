$NetBSD: patch-ui_gfx_x_generated__protos_dri3.cc,v 1.1 2025/02/06 09:58:32 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gfx/x/generated_protos/dri3.cc.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/gfx/x/generated_protos/dri3.cc
@@ -27,6 +27,8 @@
 #include <xcb/xcb.h>
 #include <xcb/xcbext.h>
 
+#include <unistd.h>
+
 #include "base/logging.h"
 #include "base/posix/eintr_wrapper.h"
 #include "ui/gfx/x/connection.h"
