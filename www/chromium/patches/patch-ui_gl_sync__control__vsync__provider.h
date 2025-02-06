$NetBSD: patch-ui_gl_sync__control__vsync__provider.h,v 1.1 2025/02/06 09:58:33 wiz Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- ui/gl/sync_control_vsync_provider.h.orig	2024-12-17 17:58:49.000000000 +0000
+++ ui/gl/sync_control_vsync_provider.h
@@ -31,7 +31,7 @@ class SyncControlVSyncProvider : public 
   bool SupportGetVSyncParametersIfAvailable() const override;
 
   static constexpr bool IsSupported() {
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
     return true;
 #else
     return false;
@@ -46,7 +46,7 @@ class SyncControlVSyncProvider : public 
   virtual bool GetMscRate(int32_t* numerator, int32_t* denominator) = 0;
 
  private:
-#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS)
+#if BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) || BUILDFLAG(IS_BSD)
   base::TimeTicks last_timebase_;
   uint64_t last_media_stream_counter_ = 0;
   base::TimeDelta last_good_interval_;
