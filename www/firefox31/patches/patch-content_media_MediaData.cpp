$NetBSD: patch-content_media_MediaData.cpp,v 1.1 2014/11/30 10:34:56 markd Exp $

Fix build with gcc 4.9
https://bugzilla.mozilla.org/show_bug.cgi?id=999496

--- content/media/MediaData.cpp.orig	2014-07-18 00:05:12.000000000 +0000
+++ content/media/MediaData.cpp
@@ -38,6 +38,16 @@ AudioData::EnsureAudioBuffer()
   }
 }
 
+size_t
+AudioData::SizeOfIncludingThis(MallocSizeOf aMallocSizeOf) const
+{
+  size_t size = aMallocSizeOf(this) + aMallocSizeOf(mAudioData);
+  if (mAudioBuffer) {
+    size += mAudioBuffer->SizeOfIncludingThis(aMallocSizeOf);
+  }
+  return size;
+}
+
 static bool
 ValidatePlane(const VideoData::YCbCrBuffer::Plane& aPlane)
 {
