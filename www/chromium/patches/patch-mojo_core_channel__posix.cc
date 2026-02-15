$NetBSD: patch-mojo_core_channel__posix.cc,v 1.5 2026/02/15 09:04:07 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- mojo/core/channel_posix.cc.orig	2026-02-03 22:07:10.000000000 +0000
+++ mojo/core/channel_posix.cc
@@ -610,6 +610,13 @@ void Channel::OfferChannelUpgrade() {
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
 
