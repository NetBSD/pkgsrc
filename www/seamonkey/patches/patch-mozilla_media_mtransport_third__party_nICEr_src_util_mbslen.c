$NetBSD: patch-mozilla_media_mtransport_third__party_nICEr_src_util_mbslen.c,v 1.4 2014/06/22 08:54:39 ryoon Exp $

--- mozilla/media/mtransport/third_party/nICEr/src/util/mbslen.c.orig	2014-06-13 00:45:42.000000000 +0000
+++ mozilla/media/mtransport/third_party/nICEr/src/util/mbslen.c
@@ -54,6 +54,13 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 # endif
 #endif
 
+#ifdef __DragonFly__
+#include <osreldate.h>
+# if __DragonFly_version > 300502
+#  define HAVE_XLOCALE
+# endif
+#endif
+
 #ifdef HAVE_XLOCALE
 #include <xlocale.h>
 #endif /* HAVE_XLOCALE */
