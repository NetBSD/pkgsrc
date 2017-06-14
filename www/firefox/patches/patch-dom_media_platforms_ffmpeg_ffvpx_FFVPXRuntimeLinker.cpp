$NetBSD: patch-dom_media_platforms_ffmpeg_ffvpx_FFVPXRuntimeLinker.cpp,v 1.2 2017/06/14 11:28:44 ryoon Exp $

--- dom/media/platforms/ffmpeg/ffvpx/FFVPXRuntimeLinker.cpp.orig	2017-06-05 20:45:19.000000000 +0000
+++ dom/media/platforms/ffmpeg/ffvpx/FFVPXRuntimeLinker.cpp
@@ -11,9 +11,13 @@
 #include "prmem.h"
 #include "prlink.h"
 
+#ifdef MOZ_SYSTEM_SOUNDTOUCH
+#include "nsXPCOMPrivate.h" // for XUL_DLL
+#else
 // We use a known symbol located in lgpllibs to determine its location.
 // soundtouch happens to be always included in lgpllibs
 #include "soundtouch/SoundTouch.h"
+#endif
 
 namespace mozilla {
 
@@ -50,6 +54,12 @@ FFVPXRuntimeLinker::Init()
 
   sLinkStatus = LinkStatus_FAILED;
 
+#ifdef MOZ_SYSTEM_SOUNDTOUCH
+  // We retrieve the path of the XUL library as this is where mozavcodec and
+  // mozavutil libs are located.
+  char* path =
+    PR_GetLibraryFilePathname(XUL_DLL, (PRFuncPtr)&FFVPXRuntimeLinker::Init);
+#else
   // We retrieve the path of the lgpllibs library as this is where mozavcodec
   // and mozavutil libs are located.
   char* lgpllibsname = PR_GetLibraryName(nullptr, "lgpllibs");
@@ -60,6 +70,7 @@ FFVPXRuntimeLinker::Init()
     PR_GetLibraryFilePathname(lgpllibsname,
                               (PRFuncPtr)&soundtouch::SoundTouch::getVersionId);
   PR_FreeLibraryName(lgpllibsname);
+#endif
   if (!path) {
     return false;
   }
