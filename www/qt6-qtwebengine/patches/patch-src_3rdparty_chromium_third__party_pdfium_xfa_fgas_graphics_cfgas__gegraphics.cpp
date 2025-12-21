$NetBSD: patch-src_3rdparty_chromium_third__party_pdfium_xfa_fgas_graphics_cfgas__gegraphics.cpp,v 1.1 2025/12/21 09:38:43 markd Exp $

--- src/3rdparty/chromium/third_party/pdfium/xfa/fgas/graphics/cfgas_gegraphics.cpp.orig	2025-10-31 08:24:51.089364742 +0000
+++ src/3rdparty/chromium/third_party/pdfium/xfa/fgas/graphics/cfgas_gegraphics.cpp
@@ -312,7 +312,7 @@ void CFGAS_GEGraphics::FillPathWithShadi
             float x = static_cast<float>(column);
             scale = (((x - start_x) * x_span) + ((y - start_y) * y_span)) /
                     axis_len_square;
-            if (isnan(scale) || scale < 0.0f) {
+            if (std::isnan(scale) || scale < 0.0f) {
               if (!m_info.fillColor.GetShading()->IsExtendedBegin())
                 continue;
               scale = 0.0f;
@@ -371,7 +371,7 @@ void CFGAS_GEGraphics::FillPathWithShadi
               continue;
             }
           }
-          if (isnan(s) || s < 0.0f) {
+          if (std::isnan(s) || s < 0.0f) {
             if (!m_info.fillColor.GetShading()->IsExtendedBegin())
               continue;
             s = 0.0f;
