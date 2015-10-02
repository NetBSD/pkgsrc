$NetBSD: patch-mozilla_gfx_thebes_gfxWindowsPlatform.cpp,v 1.1 2015/10/02 22:49:36 ryoon Exp $

--- mozilla/gfx/thebes/gfxWindowsPlatform.cpp.orig	2015-09-25 07:34:54.000000000 +0000
+++ mozilla/gfx/thebes/gfxWindowsPlatform.cpp
@@ -1876,6 +1876,10 @@ gfxWindowsPlatform::InitD3D11Devices()
     return;
   }
 
+  if (!CouldD3D11DeviceWork()) {
+    return;
+  }
+
   bool useWARP = false;
   bool allowWARP = false;
 
