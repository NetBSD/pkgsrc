$NetBSD: patch-mojo_core_channel__posix.cc,v 1.17 2026/09/29 07:43:00 kikadf Exp $

* Part of patchset to build chromium on NetBSD
* Based on OpenBSD's chromium patches, and
  pkgsrc's qt5-qtwebengine patches

--- mojo/core/channel_posix.cc.orig	2026-09-22 00:09:16.000000000 +0000
+++ mojo/core/channel_posix.cc
@@ -444,10 +444,11 @@ bool ChannelPosix::WriteNoLock(MessageVi
     if (result < 0) {
       if (errno != EAGAIN &&
           errno != EWOULDBLOCK
-#if BUILDFLAG(IS_IOS)
+#if BUILDFLAG(IS_IOS) || BUILDFLAG(IS_NETBSD)
           // On iOS if sendmsg() is trying to send fds between processes and
           // there isn't enough room in the output buffer to send the fd
-          // structure over atomically then EMSGSIZE is returned.
+          // structure over atomically then EMSGSIZE is returned. The same
+          // applies to NetBSD as well.
           //
           // EMSGSIZE presents a problem since the system APIs can only call
           // us when there's room in the socket buffer and not when there is
@@ -643,6 +644,13 @@ void Channel::OfferChannelUpgrade() {
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
 
