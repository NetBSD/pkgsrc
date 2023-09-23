$NetBSD: patch-src_win.rs,v 1.2 2023/09/23 18:25:57 vins Exp $

* Avoid cast to u64, because 32-bit ports may not implement
  u64 * u32 in rust.
* Change the cast type of 'ofs' to match the function
  parameter it's used for.
* Fix wrong call of bits() method as field.

--- src/win.rs.orig	2023-01-04 03:49:42.000000000 +0000
+++ src/win.rs
@@ -37,10 +37,10 @@ bitflags! {
         const MOUSESGR    = 1 << 9;
         const MOUSEX10    = 1 << 10;
         const MOUSEMANY   = 1 << 11;
-        const MOUSE       = (Self::MOUSEBTN.bits |
-                             Self::MOUSEMOTION.bits |
-                             Self::MOUSEX10.bits |
-                             Self::MOUSEMANY.bits);
+        const MOUSE       = (Self::MOUSEBTN.bits() |
+                             Self::MOUSEMOTION.bits() |
+                             Self::MOUSEX10.bits() |
+                             Self::MOUSEMANY.bits());
         const FOCUS       = 1 << 12;
     }
 }
@@ -678,7 +678,7 @@ impl Win {
                 return;
             }
 
-            let len = (nitems * (format as u64) / 8) as usize;
+            let len = (nitems * (format as c_ulong) / 8) as usize;
             let buf = unsafe { slice::from_raw_parts(data, len) };
             self.term_write(term, pty, buf);
             x11::XFree(data as *mut _);
@@ -686,7 +686,7 @@ impl Win {
             if rem == 0 {
                 break;
             } else {
-                ofs += (nitems * (format as u64) / 32) as i64;
+                ofs += (nitems * (format as c_ulong) / 32) as c_long;
             }
         }
     }
