$NetBSD: patch-mozilla_gfx_2d_HelpersCairo.h,v 1.1 2017/11/10 22:45:27 ryoon Exp $

--- mozilla/gfx/2d/HelpersCairo.h.orig	2017-10-16 07:17:49.000000000 +0000
+++ mozilla/gfx/2d/HelpersCairo.h
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
