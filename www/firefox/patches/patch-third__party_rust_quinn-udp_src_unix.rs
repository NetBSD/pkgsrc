$NetBSD: patch-third__party_rust_quinn-udp_src_unix.rs,v 1.1 2025/01/14 13:36:15 ryoon Exp $

--- third_party/rust/quinn-udp/src/unix.rs.orig	2024-12-26 15:01:19.823476326 +0000
+++ third_party/rust/quinn-udp/src/unix.rs
@@ -445,7 +445,7 @@ fn send(state: &UdpSocketState, io: Sock
     Ok(())
 }
 
-#[cfg(not(any(apple, target_os = "openbsd", target_os = "solaris")))]
+#[cfg(not(any(apple, target_os = "openbsd", target_os = "netbsd", target_os = "solaris")))]
 fn recv(io: SockRef<'_>, bufs: &mut [IoSliceMut<'_>], meta: &mut [RecvMeta]) -> io::Result<usize> {
     let mut names = [MaybeUninit::<libc::sockaddr_storage>::uninit(); BATCH_SIZE];
     let mut ctrls = [cmsg::Aligned(MaybeUninit::<[u8; CMSG_LEN]>::uninit()); BATCH_SIZE];
