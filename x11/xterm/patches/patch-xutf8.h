$NetBSD: patch-xutf8.h,v 1.1 2011/09/24 13:03:10 joerg Exp $

--- xutf8.h.orig	2011-09-22 20:02:00.000000000 +0000
+++ xutf8.h
@@ -21,7 +21,7 @@ OUT OF OR IN CONNECTION WITH THE SOFTWAR
 THE SOFTWARE.
 */
 
-#ifndef _XLIB_H_
+#if !defined(_XLIB_H_) && !defined(_X11_XLIB_H_)
 #error Please include <X11/Xlib.h> before "xutf8.h"
 #endif
 
