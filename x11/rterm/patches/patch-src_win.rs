$NetBSD: patch-src_win.rs,v 1.1 2023/05/25 13:50:05 he Exp $

Avoid cast to u64, because 32-bit ports may not implement
u64 * u32 in rust.
Also, change the cast type of 'ofs' to match the function
parameter it's used for.

--- src/win.rs.orig	2023-01-02 12:45:40.000000000 +0000
+++ src/win.rs
@@ -675,7 +675,7 @@ impl Win {
                 return;
             }
 
-            let len = (nitems * (format as u64) / 8) as usize;
+            let len = ((nitems * (format as u32)) / 8) as usize;
             let buf = unsafe { slice::from_raw_parts(data, len) };
             self.term_write(term, pty, buf);
             x11::XFree(data as *mut _);
@@ -683,7 +683,7 @@ impl Win {
             if rem == 0 {
                 break;
             } else {
-                ofs += (nitems * (format as u64) / 32) as i64;
+                ofs += ((nitems * (format as u32)) / 32) as c_long;
             }
         }
     }
