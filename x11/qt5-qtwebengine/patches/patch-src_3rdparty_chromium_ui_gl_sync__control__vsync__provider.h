$NetBSD: patch-src_3rdparty_chromium_ui_gl_sync__control__vsync__provider.h,v 1.1 2021/08/03 21:04:36 markd Exp $

--- src/3rdparty/chromium/ui/gl/sync_control_vsync_provider.h.orig	2020-07-15 18:56:34.000000000 +0000
+++ src/3rdparty/chromium/ui/gl/sync_control_vsync_provider.h
@@ -26,7 +26,7 @@ class SyncControlVSyncProvider : public 
   bool SupportGetVSyncParametersIfAvailable() const override;
 
   static constexpr bool IsSupported() {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     return true;
 #else
     return false;
@@ -41,7 +41,7 @@ class SyncControlVSyncProvider : public 
   virtual bool GetMscRate(int32_t* numerator, int32_t* denominator) = 0;
 
  private:
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   base::TimeTicks last_timebase_;
   uint64_t last_media_stream_counter_ = 0;
   base::TimeDelta last_good_interval_;
