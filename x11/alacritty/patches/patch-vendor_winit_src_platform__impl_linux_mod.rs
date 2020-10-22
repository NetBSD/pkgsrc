$NetBSD: patch-vendor_winit_src_platform__impl_linux_mod.rs,v 1.1 2020/10/22 14:48:17 tnn Exp $

https://github.com/rust-windowing/winit/pull/1664/commits/b1a90fd5c52ac2aff45558ff932a61892859859e

--- ../vendor/winit-0.22.2/src/platform_impl/linux/mod.rs.orig	2020-05-16 16:27:31.000000000 +0000
+++ ../vendor/winit-0.22.2/src/platform_impl/linux/mod.rs
@@ -725,7 +725,5 @@ fn is_main_thread() -> bool {
 
 #[cfg(target_os = "netbsd")]
 fn is_main_thread() -> bool {
-    use libc::_lwp_self;
-
-    unsafe { _lwp_self() == 1 }
+	std::thread::current().name() == Some("main")
 }
