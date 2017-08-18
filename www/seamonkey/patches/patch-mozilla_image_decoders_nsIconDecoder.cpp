$NetBSD: patch-mozilla_image_decoders_nsIconDecoder.cpp,v 1.1 2017/08/18 23:55:07 ryoon Exp $

--- mozilla/image/decoders/nsIconDecoder.cpp.orig	2017-07-07 05:36:37.000000000 +0000
+++ mozilla/image/decoders/nsIconDecoder.cpp
@@ -94,7 +94,8 @@ nsIconDecoder::ReadRowOfPixels(const cha
       return AsVariant(WriteState::NEED_MORE_DATA);  // Done with this row.
     }
 
-    uint32_t pixel = *reinterpret_cast<const uint32_t*>(aData);
+    uint32_t pixel;
+    memcpy(&pixel, aData, 4);
     aData += 4;
     aLength -= 4;
 
