$NetBSD: patch-gfx_layers_basic_TextureHostBasic.cpp,v 1.1 2014/05/30 03:03:36 pho Exp $

Don't assume cocoa toolkit just because OS_ARCH is Darwin.

--- gfx/layers/basic/TextureHostBasic.cpp.orig	2014-05-06 22:55:33.000000000 +0000
+++ gfx/layers/basic/TextureHostBasic.cpp
@@ -17,7 +17,7 @@ CreateTextureHostBasic(const SurfaceDesc
                        ISurfaceAllocator* aDeallocator,
                        TextureFlags aFlags)
 {
-#ifdef XP_MACOSX
+#ifdef MOZ_WIDGET_COCOA
   if (aDesc.type() == SurfaceDescriptor::TSurfaceDescriptorMacIOSurface) {
     const SurfaceDescriptorMacIOSurface& desc =
       aDesc.get_SurfaceDescriptorMacIOSurface();
