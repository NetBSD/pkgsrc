$NetBSD: patch-components_neterror_resources_neterror.js,v 1.1 2025/02/06 09:58:00 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- components/neterror/resources/neterror.js.orig	2024-12-17 17:58:49.000000000 +0000
+++ components/neterror/resources/neterror.js
@@ -142,7 +142,7 @@ function detailsButtonClick() {
 
 let primaryControlOnLeft = true;
 // clang-format off
-// <if expr="is_macosx or is_ios or is_linux or is_chromeos or is_android">
+// <if expr="is_macosx or is_ios or is_posix or is_chromeos or is_android">
 // clang-format on
 primaryControlOnLeft = false;
 // </if>
