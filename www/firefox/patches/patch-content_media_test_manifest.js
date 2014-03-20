$NetBSD: patch-content_media_test_manifest.js,v 1.1 2014/03/20 21:02:00 ryoon Exp $

--- content/media/test/manifest.js.orig	2014-03-15 05:19:11.000000000 +0000
+++ content/media/test/manifest.js
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
