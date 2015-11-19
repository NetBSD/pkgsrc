$NetBSD: patch-src_gui_painting_qpaintengine__mac.cpp,v 1.1 2015/11/19 00:06:15 wiedi Exp $

CMGetProfileByAVID and CMCloseProfile have been deprecated.
Fixes errors like:
	error: use of undeclared identifier 'CMGetProfileByAVID'
	error: use of undeclared identifier 'CMCloseProfile'

Taken from homebrew https://raw.githubusercontent.com/Homebrew/patches/480b7142c4e2ae07de6028f672695eb927a34875/qt/el-capitan.patch
which is based on upstream issue http://code.qt.io/cgit/qt/qtbase.git/commit/?id=b06304e164ba47351fa292662c1e6383c081b5ca

--- src/gui/painting/qpaintengine_mac.cpp.orig	2015-05-07 14:14:43.000000000 +0000
+++ src/gui/painting/qpaintengine_mac.cpp
@@ -340,13 +340,7 @@ CGColorSpaceRef QCoreGraphicsPaintEngine
     }
 
     // Get the color space from the display profile.
-    CGColorSpaceRef colorSpace = 0;
-    CMProfileRef displayProfile = 0;
-    CMError err = CMGetProfileByAVID((CMDisplayIDType)displayID, &displayProfile);
-    if (err == noErr) {
-        colorSpace = CGColorSpaceCreateWithPlatformColorSpace(displayProfile);
-        CMCloseProfile(displayProfile);
-    }
+    CGColorSpaceRef colorSpace = CGDisplayCopyColorSpace(displayID);
 
     // Fallback: use generic DeviceRGB
     if (colorSpace == 0)
