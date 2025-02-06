$NetBSD: patch-third__party_angle_src_libANGLE_formatutils.cpp,v 1.1 2025/02/06 09:58:22 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- third_party/angle/src/libANGLE/formatutils.cpp.orig	2024-12-17 17:58:49.000000000 +0000
+++ third_party/angle/src/libANGLE/formatutils.cpp
@@ -1475,7 +1475,7 @@ static InternalFormatInfoMap BuildIntern
     AddYUVFormat(&map,  GL_G8_B8R8_2PLANE_420_UNORM_ANGLE,            true,   8,   8,  8,   0,  0,  GL_G8_B8R8_2PLANE_420_UNORM_ANGLE,    GL_UNSIGNED_BYTE, GL_UNSIGNED_NORMALIZED, false, RequireExt<&Extensions::yuvInternalFormatANGLE>,          RequireExt<&Extensions::yuvInternalFormatANGLE>,          RequireExt<&Extensions::yuvInternalFormatANGLE>,          NeverSupported, NeverSupported);
     AddYUVFormat(&map,  GL_G8_B8_R8_3PLANE_420_UNORM_ANGLE,           true,   8,   8,  8,   0,  0,  GL_G8_B8_R8_3PLANE_420_UNORM_ANGLE,   GL_UNSIGNED_BYTE, GL_UNSIGNED_NORMALIZED, false, RequireExt<&Extensions::yuvInternalFormatANGLE>,          RequireExt<&Extensions::yuvInternalFormatANGLE>,          RequireExt<&Extensions::yuvInternalFormatANGLE>,          NeverSupported, NeverSupported);
 
-#if defined(ANGLE_PLATFORM_LINUX)
+#if defined(ANGLE_PLATFORM_LINUX) || defined(ANGLE_PLATFORM_BSD)
     // From GL_OES_required_internalformat
     // The |shared| bit shouldn't be 2. But given this hits assertion when bits
     // are checked, it's fine to have this bit set as 2 as a workaround.
