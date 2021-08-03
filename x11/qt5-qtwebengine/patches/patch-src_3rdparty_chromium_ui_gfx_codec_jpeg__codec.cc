$NetBSD: patch-src_3rdparty_chromium_ui_gfx_codec_jpeg__codec.cc,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/gfx/codec/jpeg_codec.cc.orig	2020-07-15 18:56:34.000000000 +0000
+++ src/3rdparty/chromium/ui/gfx/codec/jpeg_codec.cc
@@ -208,6 +208,7 @@ bool JPEGCodec::Decode(const unsigned ch
     case JCS_GRAYSCALE:
     case JCS_RGB:
     case JCS_YCbCr:
+#if defined(JCS_EXTENSIONS)
       // Choose an output colorspace and return if it is an unsupported one.
       // Same as JPEGCodec::Encode(), libjpeg-turbo supports all input formats
       // used by Chromium (i.e. RGBA and BGRA) and we just map the input
@@ -224,6 +225,9 @@ bool JPEGCodec::Decode(const unsigned ch
         NOTREACHED() << "Invalid pixel format";
         return false;
       }
+#else
+      cinfo.out_color_space = JCS_RGB;
+#endif
       break;
     case JCS_CMYK:
     case JCS_YCCK:
