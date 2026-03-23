$NetBSD: patch-libi3_ucs2__conversion.c,v 1.1 2026/03/23 13:09:13 nia Exp $

Fix iconv usage on SunOS and older NetBSD.

--- libi3/ucs2_conversion.c.orig	2026-02-06 07:30:55.000000000 +0000
+++ libi3/ucs2_conversion.c
@@ -12,6 +12,15 @@
 #include <stdlib.h>
 #include <string.h>
 
+#if defined(__NetBSD__)
+#include <sys/param.h>
+#if __NetBSD_Prereq__(9,99,17)
+#define NETBSD_POSIX_ICONV 1
+#else
+#define NETBSD_POSIX_ICONV 0
+#endif
+#endif
+
 static iconv_t utf8_conversion_descriptor = (iconv_t)-1;
 static iconv_t ucs2_conversion_descriptor = (iconv_t)-1;
 
@@ -42,8 +51,13 @@ char *convert_ucs2_to_utf8(xcb_char2b_t 
 
     /* Do the conversion */
     size_t input_len = num_glyphs * sizeof(xcb_char2b_t);
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+    size_t rc = iconv(utf8_conversion_descriptor, (const char **)&text,
+                      &input_len, &output, &output_size);
+#else
     size_t rc = iconv(utf8_conversion_descriptor, (char **)&text,
                       &input_len, &output, &output_size);
+#endif
     if (rc == (size_t)-1) {
         perror("Converting to UTF-8 failed");
         free(buffer);
@@ -89,8 +103,13 @@ xcb_char2b_t *convert_utf8_to_ucs2(char 
     }
 
     /* Do the conversion */
+#if (defined(__NetBSD__) && !NETBSD_POSIX_ICONV) || defined(__sun)
+    size_t rc = iconv(ucs2_conversion_descriptor, (const char **)&input, &input_size,
+                      (char **)&output, &output_bytes_left);
+#else
     size_t rc = iconv(ucs2_conversion_descriptor, &input, &input_size,
                       (char **)&output, &output_bytes_left);
+#endif
     if (rc == (size_t)-1) {
         /* Conversion will only be partial. */
         perror("Converting to UCS-2 failed");
