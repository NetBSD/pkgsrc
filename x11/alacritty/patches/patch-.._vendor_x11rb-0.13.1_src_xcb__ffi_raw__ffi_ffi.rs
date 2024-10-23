$NetBSD: patch-.._vendor_x11rb-0.13.1_src_xcb__ffi_raw__ffi_ffi.rs,v 1.1 2024/10/23 03:37:58 pin Exp $

Remove hard-coded libxcb.so paths. pkgsrc links with the correct rpath.
Needed for X11_TYPE=modular.

--- ../vendor/x11rb-0.13.1/src/xcb_ffi/raw_ffi/ffi.rs.orig	2024-10-23 03:22:01.876902589 +0000
+++ ../vendor/x11rb-0.13.1/src/xcb_ffi/raw_ffi/ffi.rs
@@ -35,18 +35,7 @@ pub(crate) mod libxcb_library {
             #[cfg(not(unix))]
             compile_error!("dl-libxcb feature is not supported on non-unix");
 
-            #[cfg(all(unix, target_os = "linux"))]
-            const LIB_NAME: &str = "libxcb.so.1";
-
-            // libtool turns -version-info differently into SONAMES on NetBSD.
-            // Also, the library is apparently not in the default search path, hence use a full path.
-            #[cfg(all(unix, target_os = "netbsd"))]
-            const LIB_NAME: &str = "/usr/X11R7/lib/libxcb.so.2";
-
-            // If we do not know anything, just assume libxcb.so and hope for the best.
-            // This is actually the right thing to do on OpenBSD since the dynamic linker then does
-            // some magic to find the right SONAME.
-            #[cfg(all(unix, not(any(target_os = "linux", target_os = "netbsd"))))]
+            #[cfg(unix)]
             const LIB_NAME: &str = "libxcb.so";
 
             let library = libloading::Library::new(LIB_NAME)
