$NetBSD: patch-mozilla_js_src_yarr_pcre_pcre.h,v 1.3 2012/04/28 22:48:06 ryoon Exp $

--- mozilla/js/src/yarr/pcre/pcre.h.orig	2012-04-23 06:27:49.000000000 +0000
+++ mozilla/js/src/yarr/pcre/pcre.h
@@ -46,7 +46,9 @@ POSSIBILITY OF SUCH DAMAGE.
 #include "assembler/wtf/Platform.h"
 #include "jsstr.h"
 #include "jsprvtd.h"
+#if ENABLE_ASSEMBLER
 #include "jstl.h"
+#endif
 
 typedef jschar UChar;
 typedef JSLinearString UString;
