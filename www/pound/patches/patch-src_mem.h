$NetBSD: patch-src_mem.h,v 1.3 2025/03/27 13:46:16 wiz Exp $

Add header for va_list.

--- src/mem.h.orig	2025-03-24 06:51:50.338105388 +0000
+++ src/mem.h
@@ -15,6 +15,8 @@
  * along with pound.  If not, see <http://www.gnu.org/licenses/>.
  */
 
+#include <stdarg.h>
+
 void *mem2nrealloc (void *p, size_t *pn, size_t s);
 void xnomem (void);
 void *xmalloc (size_t s);
