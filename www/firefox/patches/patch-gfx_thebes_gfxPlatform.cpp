$NetBSD: patch-gfx_thebes_gfxPlatform.cpp,v 1.7 2020/06/14 18:42:19 maya Exp $

Don't rely on CrossProcessSemaphore on NetBSD. It has some implementation
issues that cause issues (kern/55386, not available on NetBSD<9)

This idea is borrowed from macOS which has the same limitation.

--- gfx/thebes/gfxPlatform.cpp.orig	2020-06-03 01:04:50.000000000 +0000
+++ gfx/thebes/gfxPlatform.cpp
@@ -2922,6 +2922,10 @@ bool gfxPlatform::UsesOffMainThreadCompo
 }
 
 bool gfxPlatform::UsesTiling() const {
+#ifdef __NetBSD__
+  // Avoid relying on CrossProcessSemaphore
+  return true;
+#else
   bool usesSkia = GetDefaultContentBackend() == BackendType::SKIA;
 
   // We can't just test whether the PaintThread is initialized here because
@@ -2934,6 +2938,7 @@ bool gfxPlatform::UsesTiling() const {
   return StaticPrefs::layers_enable_tiles_AtStartup() ||
          (StaticPrefs::layers_enable_tiles_if_skia_pomtp_AtStartup() &&
           usesSkia && usesPOMTP);
+#endif
 }
 
 bool gfxPlatform::ContentUsesTiling() const {
