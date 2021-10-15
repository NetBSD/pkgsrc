$NetBSD: patch-gfx_thebes_gfxPlatform.cpp,v 1.8 2021/10/15 13:00:05 ryoon Exp $

Don't rely on CrossProcessSemaphore on NetBSD. It has some implementation
issues that cause issues (kern/55386, not available on NetBSD<9)

This idea is borrowed from macOS which has the same limitation.

--- gfx/thebes/gfxPlatform.cpp.orig	2021-09-23 21:25:31.000000000 +0000
+++ gfx/thebes/gfxPlatform.cpp
@@ -2793,7 +2793,12 @@ bool gfxPlatform::UsesOffMainThreadCompo
 }
 
 bool gfxPlatform::UsesTiling() const {
+#ifdef __NetBSD__
+  // Avoid relying on CrossProcessSemaphore
+  return true;
+#else
   return StaticPrefs::layers_enable_tiles_AtStartup();
+#endif
 }
 
 /***
