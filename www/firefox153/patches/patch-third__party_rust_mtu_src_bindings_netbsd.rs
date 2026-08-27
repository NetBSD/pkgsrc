$NetBSD: patch-third__party_rust_mtu_src_bindings_netbsd.rs,v 1.1 2026/08/27 01:23:17 gutteridge Exp $

* Fix build under NetBSD/i386 10.

--- third_party/rust/mtu/src/bindings/netbsd.rs.orig	2026-07-27 13:13:31.000000000 +0000
+++ third_party/rust/mtu/src/bindings/netbsd.rs
@@ -5,8 +5,8 @@ pub const RTAX_MAX: u32 = 9;
 pub const RTA_DST: u32 = 1;
 pub const RTA_IFP: u32 = 16;
 pub const RTAX_MAX: u32 = 9;
-pub type __int32_t = ::std::os::raw::c_int;
-pub type __int64_t = ::std::os::raw::c_long;
+pub type __int32_t = i32;
+pub type __int64_t = i64;
 pub type __pid_t = __int32_t;
 pub type u_char = ::std::os::raw::c_uchar;
 pub type u_short = ::std::os::raw::c_ushort;
@@ -19,8 +19,14 @@ const _: () = {
 }
 #[allow(clippy::unnecessary_operation, clippy::identity_op)]
 const _: () = {
+    #[cfg(target_pointer_width = "64")]
     ["Size of timespec"][::std::mem::size_of::<timespec>() - 16usize];
+    #[cfg(not(target_pointer_width = "64"))]
+    ["Size of timespec"][::std::mem::size_of::<timespec>() - 12usize];
+    #[cfg(target_pointer_width = "64")]
     ["Alignment of timespec"][::std::mem::align_of::<timespec>() - 8usize];
+    #[cfg(not(target_pointer_width = "64"))]
+    ["Alignment of timespec"][::std::mem::align_of::<timespec>() - 4usize];
     ["Offset of field: timespec::tv_sec"][::std::mem::offset_of!(timespec, tv_sec) - 0usize];
     ["Offset of field: timespec::tv_nsec"][::std::mem::offset_of!(timespec, tv_nsec) - 8usize];
 };
@@ -50,8 +56,14 @@ const _: () = {
 }
 #[allow(clippy::unnecessary_operation, clippy::identity_op)]
 const _: () = {
+    #[cfg(target_pointer_width = "64")]
     ["Size of if_data"][::std::mem::size_of::<if_data>() - 136usize];
+    #[cfg(not(target_pointer_width = "64"))]
+    ["Size of if_data"][::std::mem::size_of::<if_data>() - 132usize];
+    #[cfg(target_pointer_width = "64")]
     ["Alignment of if_data"][::std::mem::align_of::<if_data>() - 8usize];
+    #[cfg(not(target_pointer_width = "64"))]
+    ["Alignment of if_data"][::std::mem::align_of::<if_data>() - 4usize];
     ["Offset of field: if_data::ifi_type"][::std::mem::offset_of!(if_data, ifi_type) - 0usize];
     ["Offset of field: if_data::ifi_addrlen"]
         [::std::mem::offset_of!(if_data, ifi_addrlen) - 1usize];
@@ -102,7 +114,10 @@ const _: () = {
 #[allow(clippy::unnecessary_operation, clippy::identity_op)]
 const _: () = {
     ["Size of rt_metrics"][::std::mem::size_of::<rt_metrics>() - 80usize];
+    #[cfg(target_pointer_width = "64")]
     ["Alignment of rt_metrics"][::std::mem::align_of::<rt_metrics>() - 8usize];
+    #[cfg(not(target_pointer_width = "64"))]
+    ["Alignment of rt_metrics"][::std::mem::align_of::<rt_metrics>() - 4usize];
     ["Offset of field: rt_metrics::rmx_locks"]
         [::std::mem::offset_of!(rt_metrics, rmx_locks) - 0usize];
     ["Offset of field: rt_metrics::rmx_mtu"][::std::mem::offset_of!(rt_metrics, rmx_mtu) - 8usize];
@@ -143,7 +158,10 @@ const _: () = {
 #[allow(clippy::unnecessary_operation, clippy::identity_op)]
 const _: () = {
     ["Size of rt_msghdr"][::std::mem::size_of::<rt_msghdr>() - 120usize];
+    #[cfg(target_pointer_width = "64")]
     ["Alignment of rt_msghdr"][::std::mem::align_of::<rt_msghdr>() - 8usize];
+    #[cfg(not(target_pointer_width = "64"))]
+    ["Alignment of rt_msghdr"][::std::mem::align_of::<rt_msghdr>() - 4usize];
     ["Offset of field: rt_msghdr::rtm_msglen"]
         [::std::mem::offset_of!(rt_msghdr, rtm_msglen) - 0usize];
     ["Offset of field: rt_msghdr::rtm_version"]
