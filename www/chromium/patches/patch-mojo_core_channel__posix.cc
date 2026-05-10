$NetBSD: patch-mojo_core_channel__posix.cc,v 1.9 2026/05/10 15:30:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- mojo/core/channel_posix.cc.orig	2026-04-28 23:05:57.000000000 +0200
+++ mojo/core/channel_posix.cc
@@ -606,6 +606,13 @@ void Channel::OfferChannelUpgrade() {
   }
   static_cast<ChannelLinux*>(this)->OfferSharedMemUpgrade();
 }
+#elif BUILDFLAG(IS_BSD)
+// static
+bool Channel::SupportsChannelUpgrade() {
+  return false;
+}
+void Channel::OfferChannelUpgrade() {
+}
 #endif  // BUILDFLAG(IS_LINUX) || BUILDFLAG(IS_CHROMEOS) ||
         // BUILDFLAG(IS_ANDROID)
 
