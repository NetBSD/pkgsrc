$NetBSD: patch-content_media_encoder_VP8TrackEncoder.cpp,v 1.1 2015/06/30 21:09:22 markd Exp $

Deprecated names have gone completely in libvpx 1.4.0 so use prefered
ones.

--- content/media/encoder/VP8TrackEncoder.cpp.orig	2015-05-05 02:53:53.000000000 +0000
+++ content/media/encoder/VP8TrackEncoder.cpp
@@ -84,7 +84,7 @@ VP8TrackEncoder::Init(int32_t aWidth, in
   // Creating a wrapper to the image - setting image data to NULL. Actual
   // pointer will be set in encode. Setting align to 1, as it is meaningless
   // (actual memory is not allocated).
-  vpx_img_wrap(mVPXImageWrapper, IMG_FMT_I420,
+  vpx_img_wrap(mVPXImageWrapper, VPX_IMG_FMT_I420,
                mFrameWidth, mFrameHeight, 1, nullptr);
 
   config.g_w = mFrameWidth;
@@ -239,9 +239,9 @@ void VP8TrackEncoder::PrepareMutedFrame(
   uint8_t *cb = mMuteFrame.Elements() + yPlaneSize;
   uint8_t *cr = mMuteFrame.Elements() + yPlaneSize + uvPlaneSize;
 
-  mVPXImageWrapper->planes[PLANE_Y] = y;
-  mVPXImageWrapper->planes[PLANE_U] = cb;
-  mVPXImageWrapper->planes[PLANE_V] = cr;
+  mVPXImageWrapper->planes[VPX_PLANE_Y] = y;
+  mVPXImageWrapper->planes[VPX_PLANE_U] = cb;
+  mVPXImageWrapper->planes[VPX_PLANE_V] = cr;
   mVPXImageWrapper->stride[VPX_PLANE_Y] = mFrameWidth;
   mVPXImageWrapper->stride[VPX_PLANE_U] = halfWidth;
   mVPXImageWrapper->stride[VPX_PLANE_V] = halfWidth;
@@ -297,9 +297,9 @@ nsresult VP8TrackEncoder::PrepareRawFram
     const PlanarYCbCrImage::Data *data = yuv->GetData();
 
     if (isYUV420(data) && !data->mCbSkip) { // 420 planar
-      mVPXImageWrapper->planes[PLANE_Y] = data->mYChannel;
-      mVPXImageWrapper->planes[PLANE_U] = data->mCbChannel;
-      mVPXImageWrapper->planes[PLANE_V] = data->mCrChannel;
+      mVPXImageWrapper->planes[VPX_PLANE_Y] = data->mYChannel;
+      mVPXImageWrapper->planes[VPX_PLANE_U] = data->mCbChannel;
+      mVPXImageWrapper->planes[VPX_PLANE_V] = data->mCrChannel;
       mVPXImageWrapper->stride[VPX_PLANE_Y] = data->mYStride;
       mVPXImageWrapper->stride[VPX_PLANE_U] = data->mCbCrStride;
       mVPXImageWrapper->stride[VPX_PLANE_V] = data->mCbCrStride;
@@ -355,9 +355,9 @@ nsresult VP8TrackEncoder::PrepareRawFram
         return NS_ERROR_NOT_IMPLEMENTED;
       }
 
-      mVPXImageWrapper->planes[PLANE_Y] = y;
-      mVPXImageWrapper->planes[PLANE_U] = cb;
-      mVPXImageWrapper->planes[PLANE_V] = cr;
+      mVPXImageWrapper->planes[VPX_PLANE_Y] = y;
+      mVPXImageWrapper->planes[VPX_PLANE_U] = cb;
+      mVPXImageWrapper->planes[VPX_PLANE_V] = cr;
       mVPXImageWrapper->stride[VPX_PLANE_Y] = mFrameWidth;
       mVPXImageWrapper->stride[VPX_PLANE_U] = halfWidth;
       mVPXImageWrapper->stride[VPX_PLANE_V] = halfWidth;
