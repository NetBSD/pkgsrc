$NetBSD: patch-src_reqs.c,v 1.1 2012/12/13 09:01:27 wiz Exp $

Fix CVE-2012-3505 using Debian patch.

--- src/reqs.c.orig	2011-02-07 12:31:03.000000000 +0000
+++ src/reqs.c
@@ -610,6 +610,11 @@ add_header_to_connection (hashmap_t hash
         return hashmap_insert (hashofheaders, header, sep, len);
 }
 
+/* define max number of headers. big enough to handle legitimate cases,
+ * but limited to avoid DoS 
+ */
+#define MAX_HEADERS 10000
+
 /*
  * Read all the headers from the stream
  */
@@ -617,6 +622,7 @@ static int get_all_headers (int fd, hash
 {
         char *line = NULL;
         char *header = NULL;
+	int count;
         char *tmp;
         ssize_t linelen;
         ssize_t len = 0;
@@ -625,7 +631,7 @@ static int get_all_headers (int fd, hash
         assert (fd >= 0);
         assert (hashofheaders != NULL);
 
-        for (;;) {
+        for (count = 0; count < MAX_HEADERS; count++) {
                 if ((linelen = readline (fd, &line)) <= 0) {
                         safefree (header);
                         safefree (line);
@@ -691,6 +697,12 @@ static int get_all_headers (int fd, hash
 
                 safefree (line);
         }
+
+	/* if we get there, this is we reached MAX_HEADERS count.
+	   bail out with error */
+	safefree (header);
+	safefree (line);
+	return -1;
 }
 
 /*
