$NetBSD: patch-third__party_libwebrtc_webrtc_modules_audio__processing_echo__detector_mean__variance__estimator.cc,v 1.1 2021/10/15 13:00:05 ryoon Exp $

--- third_party/libwebrtc/webrtc/modules/audio_processing/echo_detector/mean_variance_estimator.cc.orig	2021-09-23 21:25:41.000000000 +0000
+++ third_party/libwebrtc/webrtc/modules/audio_processing/echo_detector/mean_variance_estimator.cc
@@ -26,8 +26,8 @@ void MeanVarianceEstimator::Update(float
   mean_ = (1.f - kAlpha) * mean_ + kAlpha * value;
   variance_ =
       (1.f - kAlpha) * variance_ + kAlpha * (value - mean_) * (value - mean_);
-  RTC_DCHECK(isfinite(mean_));
-  RTC_DCHECK(isfinite(variance_));
+  RTC_DCHECK(std::isfinite(mean_));
+  RTC_DCHECK(std::isfinite(variance_));
 }
 
 float MeanVarianceEstimator::std_deviation() const {
