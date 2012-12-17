$NetBSD: patch-tools_cachemgr.c,v 1.1 2012/12/17 13:36:21 taca Exp $

Trying to handle http://www.squid-cache.org/Advisories/SQUID-2012_1.txt.

--- tools/cachemgr.c.orig	2008-06-24 22:55:11.000000000 +0000
+++ tools/cachemgr.c
@@ -509,12 +509,15 @@ munge_action_line(const char *_buf, cach
     if ((p = strchr(x, '\n')))
 	*p = '\0';
     action = xstrtok(&x, '\t');
+    if (!action) {
+	xfree(buf);
+	return "";
+    }
     description = xstrtok(&x, '\t');
     if (!description)
 	description = action;
-    if (!action)
-	return "";
     snprintf(html, sizeof(html), " <a href=\"%s\">%s</a>", menu_url(req, action), description);
+    xfree(buf);
     return html;
 }
 
@@ -715,6 +718,7 @@ process_request(cachemgr_request * req)
     if (connect(s, (struct sockaddr *) &S, sizeof(struct sockaddr_in)) < 0) {
 	snprintf(buf, 1024, "connect: %s\n", xstrerror());
 	error_html(buf);
+	close(s);
 	return 1;
     }
     l = snprintf(buf, sizeof(buf),
@@ -765,18 +769,43 @@ read_post_request(void)
 {
     char *s;
     char *buf;
-    int len;
+    char *endptr;
+    uint64_t len;
+    size_t bufLen, readLen;
+
     if ((s = getenv("REQUEST_METHOD")) == NULL)
 	return NULL;
     if (0 != strcasecmp(s, "POST"))
 	return NULL;
     if ((s = getenv("CONTENT_LENGTH")) == NULL)
 	return NULL;
-    if ((len = atoi(s)) <= 0)
+    if (*s == '-') // negative length content huh?
+	return NULL;
+
+    endptr = s+ strlen(s);
+    if ((len = strtoll(s, &endptr, 10)) <= 0)
 	return NULL;
-    buf = xmalloc(len + 1);
-    fread(buf, len, 1, stdin);
-    buf[len] = '\0';
+
+    // limit the input to something reasonable.
+    // 4KB should be enough for the GET/POST data length, but may be extended.
+    bufLen = (len >= 4096 ? len : 4095);
+    buf = (char *)xmalloc(bufLen + 1);
+
+    readLen = fread(buf, bufLen, 1, stdin);
+    if (readLen == 0) {
+        xfree(buf);
+        return NULL;
+    }
+    buf[readLen] = '\0';
+    len -= readLen;
+
+    // purge the remainder of the request entity
+    while (len > 0) {
+        char temp[65535];
+        readLen = fread(temp, 65535, 1, stdin);
+        len -= readLen;
+    }
+
     return buf;
 }
 
@@ -886,26 +915,38 @@ decode_pub_auth(cachemgr_request * req)
     buf = xstrdup(base64_decode(req->pub_auth));
     debug(3) fprintf(stderr, "cmgr: length ok\n");
     /* parse ( a lot of memory leaks, but that is cachemgr style :) */
-    if ((host_name = strtok(buf, "|")) == NULL)
+    if ((host_name = strtok(buf, "|")) == NULL) {
+	xfree(buf);
 	return;
+    }
     debug(3) fprintf(stderr, "cmgr: decoded host: '%s'\n", host_name);
-    if ((time_str = strtok(NULL, "|")) == NULL)
+    if ((time_str = strtok(NULL, "|")) == NULL) {
+	xfree(buf);
 	return;
+    }
     debug(3) fprintf(stderr, "cmgr: decoded time: '%s' (now: %d)\n", time_str, (int) now);
-    if ((user_name = strtok(NULL, "|")) == NULL)
+    if ((user_name = strtok(NULL, "|")) == NULL) {
+        xfree(buf);
 	return;
+    }
     debug(3) fprintf(stderr, "cmgr: decoded uname: '%s'\n", user_name);
-    if ((passwd = strtok(NULL, "|")) == NULL)
+    if ((passwd = strtok(NULL, "|")) == NULL) {
+        xfree(buf);
 	return;
+    }
     debug(2) fprintf(stderr, "cmgr: decoded passwd: '%s'\n", passwd);
     /* verify freshness and validity */
-    if (atoi(time_str) + passwd_ttl < now)
+    if (atoi(time_str) + passwd_ttl < now) {
+        xfree(buf);
 	return;
-    if (strcasecmp(host_name, req->hostname))
+    }
+    if (strcasecmp(host_name, req->hostname)) {
+        xfree(buf);
 	return;
+    }
     debug(1) fprintf(stderr, "cmgr: verified auth. info.\n");
     /* ok, accept */
-    xfree(req->user_name);
+    safe_free(req->user_name);
     req->user_name = xstrdup(user_name);
     req->passwd = xstrdup(passwd);
     xfree(buf);
