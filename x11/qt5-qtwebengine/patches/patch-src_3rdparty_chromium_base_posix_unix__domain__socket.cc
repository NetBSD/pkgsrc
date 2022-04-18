$NetBSD: patch-src_3rdparty_chromium_base_posix_unix__domain__socket.cc,v 1.2 2022/04/18 11:18:18 adam Exp $

--- src/3rdparty/chromium/base/posix/unix_domain_socket.cc.orig	2021-02-19 16:41:59.000000000 +0000
+++ src/3rdparty/chromium/base/posix/unix_domain_socket.cc
@@ -6,6 +6,8 @@
 
 #include <errno.h>
 #include <sys/socket.h>
+#include <sys/types.h>
+#include <sys/ucred.h>
 #if !defined(OS_NACL_NONSFI)
 #include <sys/un.h>
 #endif
@@ -57,7 +59,7 @@ bool CreateSocketPair(ScopedFD* one, Sco
 
 // static
 bool UnixDomainSocket::EnableReceiveProcessId(int fd) {
-#if !defined(OS_APPLE)
+#if !defined(OS_APPLE) && !defined(OS_NETBSD)
   const int enable = 1;
   return setsockopt(fd, SOL_SOCKET, SO_PASSCRED, &enable, sizeof(enable)) == 0;
 #else
@@ -151,7 +153,11 @@ ssize_t UnixDomainSocket::RecvMsgWithFla
 #if !defined(OS_NACL_NONSFI) && !defined(OS_APPLE)
       // The PNaCl toolchain for Non-SFI binary build and macOS do not support
       // ucred. macOS supports xucred, but this structure is insufficient.
+#if defined(OS_NETBSD)
+      + CMSG_SPACE(sizeof(struct unpcbid))
+#else
       + CMSG_SPACE(sizeof(struct ucred))
+#endif
 #endif  // !defined(OS_NACL_NONSFI) && !defined(OS_APPLE)
       ;
   char control_buffer[kControlBufferSize];
@@ -176,7 +182,7 @@ ssize_t UnixDomainSocket::RecvMsgWithFla
         wire_fds = reinterpret_cast<int*>(CMSG_DATA(cmsg));
         wire_fds_len = payload_len / sizeof(int);
       }
-#if !defined(OS_NACL_NONSFI) && !defined(OS_APPLE)
+#if !defined(OS_NACL_NONSFI) && !defined(OS_APPLE) && !defined(OS_NETBSD)
       // The PNaCl toolchain for Non-SFI binary build and macOS do not support
       // SCM_CREDENTIALS.
       if (cmsg->cmsg_level == SOL_SOCKET &&
@@ -211,6 +217,12 @@ ssize_t UnixDomainSocket::RecvMsgWithFla
     socklen_t pid_size = sizeof(pid);
     if (getsockopt(fd, SOL_LOCAL, LOCAL_PEERPID, &pid, &pid_size) != 0)
       pid = -1;
+#elif defined(OS_NETBSD)
+    socklen_t pid_size = sizeof(pid);
+    struct unpcbid cred;
+    if (getsockopt(fd, 0, LOCAL_PEEREID, &cred, &pid_size) != 0)
+      pid = -1;
+    pid = cred.unp_pid;
 #else
     // |pid| will legitimately be -1 if we read EOF, so only DCHECK if we
     // actually received a message.  Unfortunately, Linux allows sending zero
