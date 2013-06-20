$NetBSD: patch-support_passwd__common.c,v 1.1 2013/06/20 09:06:45 taca Exp $

Fix for htpasswd: https://issues.apache.org/bugzilla/show_bug.cgi?id=54735

--- support/passwd_common.c.orig	2012-12-11 10:37:25.000000000 +0000
+++ support/passwd_common.c
@@ -46,6 +46,24 @@
 
 apr_file_t *errfile;
 
+int abort_on_oom(int rc)
+{
+    const char *buf = "Error: out of memory\n";
+    int written, count = strlen(buf);
+    do {
+        written = write(STDERR_FILENO, buf, count);
+        if (written == count)
+            break;
+        if (written > 0) {
+            buf += written;
+            count -= written;
+        }
+    } while (written >= 0 || errno == EINTR);
+    abort();
+    /* NOTREACHED */
+    return 0;
+}
+
 static int generate_salt(char *s, size_t size, const char **errstr,
                          apr_pool_t *pool)
 {
@@ -85,6 +103,8 @@ static int generate_salt(char *s, size_t
 void putline(apr_file_t *f, const char *l)
 {
     apr_status_t rv;
+    if (f == NULL)
+        return;
     rv = apr_file_puts(l, f);
     if (rv != APR_SUCCESS) {
         apr_file_printf(errfile, "Error writing temp file: %pm", &rv);
@@ -95,17 +115,17 @@ void putline(apr_file_t *f, const char *
 
 int get_password(struct passwd_ctx *ctx)
 {
+    char buf[MAX_STRING_LEN + 1];
     if (ctx->passwd_src == PW_STDIN) {
-        char *buf = ctx->out;
         apr_file_t *file_stdin;
         apr_size_t nread;
         if (apr_file_open_stdin(&file_stdin, ctx->pool) != APR_SUCCESS) {
             ctx->errstr = "Unable to read from stdin.";
             return ERR_GENERAL;
         }
-        if (apr_file_read_full(file_stdin, buf, ctx->out_len - 1,
+        if (apr_file_read_full(file_stdin, buf, sizeof(buf) - 1,
                                &nread) != APR_EOF
-            || nread == ctx->out_len - 1) {
+            || nread == sizeof(buf) - 1) {
             goto err_too_long;
         }
         buf[nread] = '\0';
@@ -115,21 +135,30 @@ int get_password(struct passwd_ctx *ctx)
                 buf[nread-2] = '\0';
         }
         apr_file_close(file_stdin);
+        ctx->passwd = apr_pstrdup(ctx->pool, buf);
+    }
+    else if (ctx->passwd_src == PW_PROMPT_VERIFY) {
+        apr_size_t bufsize = sizeof(buf);
+        if (apr_password_get("Enter password: ", buf, &bufsize) != 0)
+            goto err_too_long;
+        ctx->passwd = apr_pstrdup(ctx->pool, buf);
     }
     else {
-        char buf[MAX_STRING_LEN + 1];
         apr_size_t bufsize = sizeof(buf);
-        if (apr_password_get("New password: ", ctx->out, &ctx->out_len) != 0)
+        if (apr_password_get("New password: ", buf, &bufsize) != 0)
             goto err_too_long;
+        ctx->passwd = apr_pstrdup(ctx->pool, buf);
+        bufsize = sizeof(buf);
+        buf[0] = '\0';
         apr_password_get("Re-type new password: ", buf, &bufsize);
-        if (strcmp(ctx->out, buf) != 0) {
+        if (strcmp(ctx->passwd, buf) != 0) {
             ctx->errstr = "password verification error";
-            memset(ctx->out, '\0', ctx->out_len);
+            memset(ctx->passwd, '\0', strlen(ctx->passwd));
             memset(buf, '\0', sizeof(buf));
             return ERR_PWMISMATCH;
         }
-        memset(buf, '\0', sizeof(buf));
     }
+    memset(buf, '\0', sizeof(buf));
     return 0;
 
 err_too_long:
@@ -146,7 +175,6 @@ err_too_long:
 int mkhash(struct passwd_ctx *ctx)
 {
     char *pw;
-    char pwin[MAX_STRING_LEN];
     char salt[16];
     apr_status_t rv;
     int ret = 0;
@@ -159,14 +187,11 @@ int mkhash(struct passwd_ctx *ctx)
                         "Warning: Ignoring -C argument for this algorithm." NL);
     }
 
-    if (ctx->passwd != NULL) {
-        pw = ctx->passwd;
-    }
-    else {
+    if (ctx->passwd == NULL) {
         if ((ret = get_password(ctx)) != 0)
             return ret;
-        pw = pwin;
     }
+    pw = ctx->passwd;
 
     switch (ctx->alg) {
     case ALG_APSHA:
@@ -206,14 +231,13 @@ int mkhash(struct passwd_ctx *ctx)
 
         apr_cpystrn(ctx->out, cbuf, ctx->out_len - 1);
         if (strlen(pw) > 8) {
-            char *truncpw = strdup(pw);
+            char *truncpw = apr_pstrdup(ctx->pool, pw);
             truncpw[8] = '\0';
             if (!strcmp(ctx->out, crypt(truncpw, salt))) {
                 apr_file_printf(errfile, "Warning: Password truncated to 8 "
                                 "characters by CRYPT algorithm." NL);
             }
             memset(truncpw, '\0', strlen(pw));
-            free(truncpw);
         }
         break;
 #endif /* CRYPT_ALGO_SUPPORTED */
