$NetBSD: patch-src_3rdparty_chromium_components_neterror_resources_neterror.js,v 1.1 2021/08/03 21:04:35 markd Exp $

--- src/3rdparty/chromium/components/neterror/resources/neterror.js.orig	2020-07-08 21:40:39.000000000 +0000
+++ src/3rdparty/chromium/components/neterror/resources/neterror.js
@@ -204,7 +204,7 @@ function setUpCachedButton(buttonStrings
 }
 
 let primaryControlOnLeft = true;
-// <if expr="is_macosx or is_ios or is_linux or is_android">
+// <if expr="is_macosx or is_ios or is_linux or is_android or is_bsd">
 primaryControlOnLeft = false;
 // </if>
 
