$NetBSD: patch-src_3rdparty_chromium_mojo_core_channel__posix.cc,v 1.1 2026/10/02 13:08:36 kikadf Exp $

* Workaround to the renderer process crash

--- src/3rdparty/chromium/mojo/core/channel_posix.cc.orig	2026-10-02 06:55:56.671304457 +0000
+++ src/3rdparty/chromium/mojo/core/channel_posix.cc
@@ -409,10 +409,11 @@ bool ChannelPosix::WriteNoLock(MessageVi
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
