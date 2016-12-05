$NetBSD: patch-image_decoders_nsIconDecoder.cpp,v 1.1 2016/12/05 11:54:45 martin Exp $

Bugzilla #1322112

--- image/decoders/nsIconDecoder.cpp.orig	2016-10-31 21:15:32.000000000 +0100
+++ image/decoders/nsIconDecoder.cpp	2016-12-05 11:58:01.896240403 +0100
@@ -97,7 +97,8 @@ nsIconDecoder::ReadRowOfPixels(const cha
       return AsVariant(WriteState::NEED_MORE_DATA);  // Done with this row.
     }
 
-    uint32_t pixel = *reinterpret_cast<const uint32_t*>(aData);
+    uint32_t pixel;
+    memcpy(&pixel, aData, 4);
     aData += 4;
     aLength -= 4;
 
