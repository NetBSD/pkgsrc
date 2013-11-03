$NetBSD: patch-media_mtransport_third__party_nICEr_src_util_mbslen.c,v 1.1 2013/11/03 04:51:59 ryoon Exp $

--- media/mtransport/third_party/nICEr/src/util/mbslen.c.orig	2013-06-17 22:13:19.000000000 +0000
+++ media/mtransport/third_party/nICEr/src/util/mbslen.c
@@ -43,9 +43,17 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 #include <locale.h>
 #include <stdlib.h>
 #include <wchar.h>
-#ifdef DARWIN
+
+#ifdef __FreeBSD__
+#include <osreldate.h>
+# if __FreeBSD_version > 900505
+#  define HAVE_XLOCALE
+# endif
+#endif
+
+#ifdef HAVE_XLOCALE
 #include <xlocale.h>
-#endif /* DARWIN */
+#endif /* HAVE_XLOCALE */
 
 #include "nr_api.h"
 #include "mbslen.h"
@@ -54,10 +62,10 @@ OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 int
 mbslen(const char *s, size_t *ncharsp)
 {
-#ifdef DARWIN
+#ifdef HAVE_XLOCALE
     static locale_t loc = 0;
     static int initialized = 0;
-#endif /* DARWIN */
+#endif /* HAVE_XLOCALE */
 #ifdef WIN32
     char *my_locale=0;
     unsigned int i;
@@ -67,7 +75,7 @@ mbslen(const char *s, size_t *ncharsp)
     int nchars;
     mbstate_t mbs;
 
-#ifdef DARWIN
+#ifdef HAVE_XLOCALE
     if (! initialized) {
         initialized = 1;
         loc = newlocale(LC_CTYPE_MASK, "UTF-8", LC_GLOBAL_LOCALE);
@@ -76,7 +84,7 @@ mbslen(const char *s, size_t *ncharsp)
     if (loc == 0) {
         /* unable to create the UTF-8 locale */
         assert(loc != 0);  /* should never happen */
-#endif /* DARWIN */
+#endif /* HAVE_XLOCALE */
 
 #ifdef WIN32
     if (!setlocale(LC_CTYPE, 0))
@@ -99,18 +107,18 @@ mbslen(const char *s, size_t *ncharsp)
         ABORT(R_NOT_FOUND);
 #endif
 
-#ifdef DARWIN
+#ifdef HAVE_XLOCALE
     }
-#endif /* DARWIN */
+#endif /* HAVE_XLOCALE */
 
     memset(&mbs, 0, sizeof(mbs));
     nchars = 0;
 
-#ifdef DARWIN
+#ifdef HAVE_XLOCALE
     while (*s != '\0' && (nbytes = mbrlen_l(s, strlen(s), &mbs, loc)) != 0)
 #else
     while (*s != '\0' && (nbytes = mbrlen(s, strlen(s), &mbs)) != 0)
-#endif /* DARWIN */
+#endif /* HAVE_XLOCALE */
     {
         if (nbytes == (size_t)-1)   /* should never happen */ {
             ABORT(R_INTERNAL);
