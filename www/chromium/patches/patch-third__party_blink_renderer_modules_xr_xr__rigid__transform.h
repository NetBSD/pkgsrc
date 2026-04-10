$NetBSD: patch-third__party_blink_renderer_modules_xr_xr__rigid__transform.h,v 1.3 2026/04/10 17:31:59 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/blink/renderer/modules/xr/xr_rigid_transform.h.orig	2026-04-06 16:25:54.000000000 +0000
+++ third_party/blink/renderer/modules/xr/xr_rigid_transform.h
@@ -12,9 +12,7 @@
 #include "third_party/blink/renderer/modules/modules_export.h"
 #include "third_party/blink/renderer/platform/bindings/script_wrappable.h"
 
-namespace gfx {
-class Transform;
-}
+#include "ui/gfx/geometry/transform.h"
 
 namespace blink {
 
