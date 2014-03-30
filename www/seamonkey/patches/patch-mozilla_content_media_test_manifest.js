$NetBSD: patch-mozilla_content_media_test_manifest.js,v 1.1 2014/03/30 04:13:17 ryoon Exp $

--- mozilla/content/media/test/manifest.js.orig	2014-03-19 01:41:47.000000000 +0000
+++ mozilla/content/media/test/manifest.js
@@ -357,9 +357,9 @@ var gUnseekableTests = [
   { name:"bogus.duh", type:"bogus/duh"}
 ];
 // Unfortunately big-buck-bunny-unseekable.mp4 is doesn't play on Windows 7, so
-// only include it in the unseekable tests if we're on later versions of Windows.
-if (navigator.userAgent.indexOf("Windows") == -1 ||
-    IsWindows8OrLater()) {
+// only include it in the unseekable tests if we're on later versions of Windows. 
+// This test actually only passes on win8 at the moment.
+if (navigator.userAgent.indexOf("Windows") != -1 && IsWindows8OrLater()) {
   gUnseekableTests = gUnseekableTests.concat([
     { name:"big-buck-bunny-unseekable.mp4", type:"video/mp4" }
   ]);
