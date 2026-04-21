$NetBSD: patch-ui_gl_gl__context.cc,v 1.18 2026/04/21 15:21:24 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gl/gl_context.cc.orig	2026-04-14 23:31:37.000000000 +0200
+++ ui/gl/gl_context.cc
@@ -153,7 +153,7 @@ bool GLContext::MakeCurrent(GLSurface* s
     recorded_max_gles_version_if_feasible = true;
   }
 #elif (BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_MAC) || \
-       BUILDFLAG(IS_WIN))
+       BUILDFLAG(IS_WIN) || BUILDFLAG(IS_BSD))
   static bool recorded_emulated_gles_version = false;
   if (!recorded_emulated_gles_version) {
     base::UmaHistogramBoolean("GPU.ANGLECanEmulateGLES3",
@@ -431,7 +431,7 @@ bool GLContext::MakeVirtuallyCurrent(
   DCHECK(virtual_context->IsCurrent(surface));
 
   if (switched_real_contexts || virtual_context != current_virtual_context_) {
-#if DCHECK_IS_ON()
+#if DCHECK_IS_ON() && !BUILDFLAG(IS_BSD)
     GLenum error = glGetError();
     // Accepting a context loss error here enables using debug mode to work on
     // context loss handling in virtual context mode.
