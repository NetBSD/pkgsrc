$NetBSD: patch-src_plugins_avfoundation_camera_avfcamerautility.mm,v 1.1 2024/05/31 06:17:46 adam Exp $

std::unary_function is deprecated in C++11.

--- src/plugins/avfoundation/camera/avfcamerautility.mm.orig	2024-05-31 06:13:49.304697096 +0000
+++ src/plugins/avfoundation/camera/avfcamerautility.mm
@@ -101,7 +101,7 @@ struct ByResolution
     }
 };
 
-struct FormatHasNoFPSRange : std::unary_function<AVCaptureDeviceFormat *, bool>
+struct FormatHasNoFPSRange : std::function<bool (AVCaptureDeviceFormat *)>
 {
     bool operator() (AVCaptureDeviceFormat *format)
     {
