$NetBSD: patch-mozilla_js_src_yarr_pcre_pcre.h,v 1.2 2012/03/19 10:36:00 ryoon Exp $

--- mozilla/js/src/yarr/pcre/pcre.h.orig	2012-03-13 05:32:47.000000000 +0000
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
