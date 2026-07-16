$NetBSD: patch-dom_media_platforms_ffmpeg_FFmpegVulkanVideoDecoder.cpp,v 1.1 2026/07/16 13:11:49 ryoon Exp $

* Fix build under 32-bit platforms.

--- dom/media/platforms/ffmpeg/FFmpegVulkanVideoDecoder.cpp.orig	2026-07-15 02:16:21.002811402 +0000
+++ dom/media/platforms/ffmpeg/FFmpegVulkanVideoDecoder.cpp
@@ -117,8 +117,8 @@ void FFmpegVideoDecoder<LIBAV_VER>::FFmpegVulkanVideoD
   mDeviceFunctions.Clear();
 
   for (int i = 0; i < kNumBuffers; i++) {
-    mNv12Image[i] = nullptr;
-    mNv12Mem[i] = nullptr;
+    mNv12Image[i] = VK_NULL_HANDLE;
+    mNv12Mem[i] = VK_NULL_HANDLE;
     mNv12BaseFd[i] = -1;
     mCopyDoneSem[i] = VK_NULL_HANDLE;
     mCopyDoneSemFd[i] = -1;
@@ -796,11 +796,11 @@ FFmpegVideoDecoder<LIBAV_VER>::FFmpegVulkanVideoDecode
     }
     if (mNv12Image[buf]) {
       mDestroyImage(mDevice, mNv12Image[buf], nullptr);
-      mNv12Image[buf] = nullptr;
+      mNv12Image[buf] = VK_NULL_HANDLE;
     }
     if (mNv12Mem[buf]) {
       mFreeMemory(mDevice, mNv12Mem[buf], nullptr);
-      mNv12Mem[buf] = nullptr;
+      mNv12Mem[buf] = VK_NULL_HANDLE;
     }
   }
 
@@ -842,11 +842,11 @@ FFmpegVideoDecoder<LIBAV_VER>::FFmpegVulkanVideoDecode
       }
       if (mNv12Mem[b]) {
         mFreeMemory(mDevice, mNv12Mem[b], nullptr);
-        mNv12Mem[b] = nullptr;
+        mNv12Mem[b] = VK_NULL_HANDLE;
       }
       if (mNv12Image[b]) {
         mDestroyImage(mDevice, mNv12Image[b], nullptr);
-        mNv12Image[b] = nullptr;
+        mNv12Image[b] = VK_NULL_HANDLE;
       }
     }
   });
@@ -924,7 +924,7 @@ FFmpegVideoDecoder<LIBAV_VER>::FFmpegVulkanVideoDecode
     }
     if (memTypeIndex == UINT32_MAX) {
       mDestroyImage(mDevice, mNv12Image[buf], nullptr);
-      mNv12Image[buf] = nullptr;
+      mNv12Image[buf] = VK_NULL_HANDLE;
       return MediaResult(
           NS_ERROR_DOM_MEDIA_FATAL_ERR,
           RESULT_DETAIL("No compatible memory type for NV12 image"));
@@ -944,7 +944,7 @@ FFmpegVideoDecoder<LIBAV_VER>::FFmpegVulkanVideoDecode
     res = mAllocateMemory(mDevice, &allocInfo, nullptr, &mNv12Mem[buf]);
     if (res != VK_SUCCESS) {
       mDestroyImage(mDevice, mNv12Image[buf], nullptr);
-      mNv12Image[buf] = nullptr;
+      mNv12Image[buf] = VK_NULL_HANDLE;
       return MediaResult(NS_ERROR_DOM_MEDIA_FATAL_ERR,
                          RESULT_DETAIL("Failed to alloc NV12 memory"));
     }
@@ -953,8 +953,8 @@ FFmpegVideoDecoder<LIBAV_VER>::FFmpegVulkanVideoDecode
     if (res != VK_SUCCESS) {
       mFreeMemory(mDevice, mNv12Mem[buf], nullptr);
       mDestroyImage(mDevice, mNv12Image[buf], nullptr);
-      mNv12Mem[buf] = nullptr;
-      mNv12Image[buf] = nullptr;
+      mNv12Mem[buf] = VK_NULL_HANDLE;
+      mNv12Image[buf] = VK_NULL_HANDLE;
       return MediaResult(NS_ERROR_DOM_MEDIA_FATAL_ERR,
                          RESULT_DETAIL("Failed to bind NV12 memory"));
     }
@@ -981,8 +981,8 @@ FFmpegVideoDecoder<LIBAV_VER>::FFmpegVulkanVideoDecode
     if (res != VK_SUCCESS) {
       mFreeMemory(mDevice, mNv12Mem[buf], nullptr);
       mDestroyImage(mDevice, mNv12Image[buf], nullptr);
-      mNv12Mem[buf] = nullptr;
-      mNv12Image[buf] = nullptr;
+      mNv12Mem[buf] = VK_NULL_HANDLE;
+      mNv12Image[buf] = VK_NULL_HANDLE;
       return MediaResult(NS_ERROR_DOM_MEDIA_FATAL_ERR,
                          RESULT_DETAIL("Failed to export NV12 FD"));
     }
