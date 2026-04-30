$NetBSD: patch-src_3rdparty_chromium_third__party_pdfium_xfa_fgas_graphics_cfgas__gegraphics.cpp,v 1.2 2026/04/30 06:39:44 adam Exp $

--- src/3rdparty/chromium/third_party/pdfium/xfa/fgas/graphics/cfgas_gegraphics.cpp.orig	2026-03-16 11:40:07.000000000 +0000
+++ src/3rdparty/chromium/third_party/pdfium/xfa/fgas/graphics/cfgas_gegraphics.cpp
@@ -313,7 +313,7 @@ void CFGAS_GEGraphics::FillPathWithShadi
             float x = static_cast<float>(column);
             scale = (((x - start_x) * x_span) + ((y - start_y) * y_span)) /
                     axis_len_square;
-            if (isnan(scale) || scale < 0.0f) {
+            if (std::isnan(scale) || scale < 0.0f) {
               if (!info_.fillColor.GetShading()->IsExtendedBegin()) {
                 continue;
               }
@@ -374,7 +374,7 @@ void CFGAS_GEGraphics::FillPathWithShadi
               continue;
             }
           }
-          if (isnan(s) || s < 0.0f) {
+          if (std::isnan(s) || s < 0.0f) {
             if (!info_.fillColor.GetShading()->IsExtendedBegin()) {
               continue;
             }
