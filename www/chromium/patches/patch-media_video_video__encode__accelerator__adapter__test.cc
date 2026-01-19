$NetBSD: patch-media_video_video__encode__accelerator__adapter__test.cc,v 1.14 2026/01/19 16:14:17 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- media/video/video_encode_accelerator_adapter_test.cc.orig	2026-01-07 00:50:30.000000000 +0000
+++ media/video/video_encode_accelerator_adapter_test.cc
@@ -259,7 +259,7 @@ TEST_F(VideoEncodeAcceleratorAdapterTest
       });
 
   VideoPixelFormat expected_input_format = PIXEL_FORMAT_I420;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   expected_input_format = PIXEL_FORMAT_NV12;
 #endif
   vea()->SetEncodingCallback(base::BindLambdaForTesting(
@@ -368,7 +368,7 @@ TEST_F(VideoEncodeAcceleratorAdapterTest
       });
 
   VideoPixelFormat expected_input_format = PIXEL_FORMAT_I420;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   expected_input_format = PIXEL_FORMAT_NV12;
 #endif
 
@@ -466,7 +466,7 @@ TEST_P(VideoEncodeAcceleratorAdapterTest
       CreateGreenFrame(large_size, pixel_format, base::Milliseconds(2));
 
   VideoPixelFormat expected_input_format = PIXEL_FORMAT_I420;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     expected_input_format = PIXEL_FORMAT_NV12;
 #endif
   const gfx::ColorSpace expected_color_space =
@@ -713,7 +713,7 @@ TEST_F(VideoEncodeAcceleratorAdapterTest
       });
 
   VideoPixelFormat expected_input_format = PIXEL_FORMAT_I420;
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   expected_input_format = PIXEL_FORMAT_NV12;
 #endif
   vea()->SetEncodingCallback(base::BindLambdaForTesting(
