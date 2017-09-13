$NetBSD: patch-gfx_2d_HelpersCairo.h,v 1.1 2017/09/13 10:03:47 martin Exp $

Total hack: avoid lots of debug spew on big endian platforms
(there is a real bug involved here, but this does not help
debugging)

--- gfx/2d/HelpersCairo.h.orig	2017-04-11 04:13:04.000000000 +0200
+++ gfx/2d/HelpersCairo.h	2017-09-13 11:19:21.840242779 +0200
@@ -160,7 +160,9 @@ GfxFormatToCairoFormat(SurfaceFormat for
     case SurfaceFormat::R5G6B5_UINT16:
       return CAIRO_FORMAT_RGB16_565;
     default:
+#if MOZ_LITTLE_ENDIAN
       gfxCriticalError() << "Unknown image format " << (int)format;
+#endif
       return CAIRO_FORMAT_ARGB32;
   }
 }
