$NetBSD: patch-gfx_thebes_gfxWindowsPlatform.cpp,v 1.1 2015/09/23 06:44:42 ryoon Exp $

--- gfx/thebes/gfxWindowsPlatform.cpp.orig	2015-08-24 21:53:05.000000000 +0000
+++ gfx/thebes/gfxWindowsPlatform.cpp
@@ -1879,6 +1879,10 @@ gfxWindowsPlatform::InitD3D11Devices()
     return;
   }
 
+  if (!CouldD3D11DeviceWork()) {
+    return;
+  }
+
   bool useWARP = false;
   bool allowWARP = false;
 
