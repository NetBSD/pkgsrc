$NetBSD: patch-leftwm-core_src_display__servers_xlib__display__server_xwrap_getters.rs,v 1.1 2022/02/27 20:36:26 pin Exp $

Fix build errors on architectures with u8, patch by pkubaj

--- leftwm-core/src/display_servers/xlib_display_server/xwrap/getters.rs.orig	2021-12-13 13:37:54.000000000 +0000
+++ leftwm-core/src/display_servers/xlib_display_server/xwrap/getters.rs
@@ -3,7 +3,7 @@ use super::{Screen, WindowHandle, XlibEr
 use crate::models::{DockArea, WindowState, WindowType, XyhwChange};
 use crate::XWrap;
 use std::ffi::CString;
-use std::os::raw::{c_int, c_long, c_uchar, c_uint, c_ulong};
+use std::os::raw::{c_char, c_int, c_long, c_uchar, c_uint, c_ulong};
 use std::slice;
 use x11_dl::xlib;
 
@@ -575,7 +575,7 @@ impl XWrap {
             if status == 0 {
                 return Err(XlibError::FailedStatus);
             }
-            if let Ok(s) = CString::from_raw(text_prop.value.cast::<i8>()).into_string() {
+            if let Ok(s) = CString::from_raw(text_prop.value.cast::<c_char>()).into_string() {
                 return Ok(s);
             }
         };
