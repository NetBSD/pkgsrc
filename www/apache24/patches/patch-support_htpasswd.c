$NetBSD: patch-support_htpasswd.c,v 1.1 2013/06/20 09:06:45 taca Exp $

Fix for htpasswd: https://issues.apache.org/bugzilla/show_bug.cgi?id=54735

--- support/htpasswd.c.orig	2012-12-12 19:31:29.000000000 +0000
+++ support/htpasswd.c
@@ -67,6 +67,7 @@
 #define APHTP_NEWFILE        1
 #define APHTP_NOFILE         2
 #define APHTP_DELUSER        4
+#define APHTP_VERIFY         8
 
 apr_file_t *ftemp = NULL;
 
@@ -92,8 +93,8 @@ static int mkrecord(struct passwd_ctx *c
 static void usage(void)
 {
     apr_file_printf(errfile, "Usage:" NL
-        "\thtpasswd [-cimBdpsD] [-C cost] passwordfile username" NL
-        "\thtpasswd -b[cmBdpsD] [-C cost] passwordfile username password" NL
+        "\thtpasswd [-cimBdpsDv] [-C cost] passwordfile username" NL
+        "\thtpasswd -b[cmBdpsDv] [-C cost] passwordfile username password" NL
         NL
         "\thtpasswd -n[imBdps] [-C cost] username" NL
         "\thtpasswd -nb[mBdps] [-C cost] username password" NL
@@ -110,6 +111,7 @@ static void usage(void)
         " -s  Force SHA encryption of the password (insecure)." NL
         " -p  Do not encrypt the password (plaintext, insecure)." NL
         " -D  Delete the specified user." NL
+        " -v  Verify password for the specified user." NL
         "On other systems than Windows and NetWare the '-p' flag will "
             "probably not work." NL
         "The SHA algorithm does not use a salt and is less secure than the "
@@ -155,7 +157,7 @@ static void terminate(void)
 }
 
 static void check_args(int argc, const char *const argv[],
-                       struct passwd_ctx *ctx, int *mask, char **user,
+                       struct passwd_ctx *ctx, unsigned *mask, char **user,
                        char **pwfilename)
 {
     const char *arg;
@@ -171,7 +173,7 @@ static void check_args(int argc, const c
     if (rv != APR_SUCCESS)
         exit(ERR_SYNTAX);
 
-    while ((rv = apr_getopt(state, "cnmspdBbDiC:", &opt, &opt_arg)) == APR_SUCCESS) {
+    while ((rv = apr_getopt(state, "cnmspdBbDiC:v", &opt, &opt_arg)) == APR_SUCCESS) {
         switch (opt) {
         case 'c':
             *mask |= APHTP_NEWFILE;
@@ -183,6 +185,9 @@ static void check_args(int argc, const c
         case 'D':
             *mask |= APHTP_DELUSER;
             break;
+        case 'v':
+            *mask |= APHTP_VERIFY;
+            break;
         default:
             ret = parse_common_options(ctx, opt, opt_arg);
             if (ret) {
@@ -196,18 +201,15 @@ static void check_args(int argc, const c
     if (rv != APR_EOF)
         usage();
 
-    if ((*mask & APHTP_NEWFILE) && (*mask & APHTP_NOFILE)) {
-        apr_file_printf(errfile, "%s: -c and -n options conflict" NL, argv[0]);
-        exit(ERR_SYNTAX);
-    }
-    if ((*mask & APHTP_NEWFILE) && (*mask & APHTP_DELUSER)) {
-        apr_file_printf(errfile, "%s: -c and -D options conflict" NL, argv[0]);
-        exit(ERR_SYNTAX);
-    }
-    if ((*mask & APHTP_NOFILE) && (*mask & APHTP_DELUSER)) {
-        apr_file_printf(errfile, "%s: -n and -D options conflict" NL, argv[0]);
+    if ((*mask) & (*mask - 1)) {
+        /* not a power of two, i.e. more than one flag specified */
+        apr_file_printf(errfile, "%s: only one of -c -n -v -D may be specified" NL,
+            argv[0]);
         exit(ERR_SYNTAX);
     }
+    if ((*mask & APHTP_VERIFY) && ctx->passwd_src == PW_PROMPT)
+        ctx->passwd_src = PW_PROMPT_VERIFY;
+
     /*
      * Make sure we still have exactly the right number of arguments left
      * (the filename, the username, and possibly the password if -b was
@@ -246,6 +248,25 @@ static void check_args(int argc, const c
     }
 }
 
+static int verify(struct passwd_ctx *ctx, const char *hash)
+{
+    apr_status_t rv;
+    int ret;
+
+    if (ctx->passwd == NULL && (ret = get_password(ctx)) != 0)
+       return ret;
+    rv = apr_password_validate(ctx->passwd, hash);
+    if (rv == APR_SUCCESS)
+        return 0;
+    if (APR_STATUS_IS_EMISMATCH(rv)) {
+        ctx->errstr = "password verification failed";
+        return ERR_PWMISMATCH;
+    }
+    ctx->errstr = apr_psprintf(ctx->pool, "Could not verify password: %pm",
+                               &rv);
+    return ERR_GENERAL;
+}
+
 /*
  * Let's do it.  We end up doing a lot of file opening and closing,
  * but what do we care?  This application isn't run constantly.
@@ -253,7 +274,6 @@ static void check_args(int argc, const c
 int main(int argc, const char * const argv[])
 {
     apr_file_t *fpw = NULL;
-    const char *errstr = NULL;
     char line[MAX_STRING_LEN];
     char *pwfilename = NULL;
     char *user = NULL;
@@ -262,7 +282,7 @@ int main(int argc, const char * const ar
     char *scratch, cp[MAX_STRING_LEN];
     int found = 0;
     int i;
-    int mask = 0;
+    unsigned mask = 0;
     apr_pool_t *pool;
     int existing_file = 0;
     struct passwd_ctx ctx = { 0 };
@@ -274,6 +294,7 @@ int main(int argc, const char * const ar
     apr_app_initialize(&argc, &argv, NULL);
     atexit(terminate);
     apr_pool_create(&pool, NULL);
+    apr_pool_abort_set(abort_on_oom, pool);
     apr_file_open_stderr(&errfile, pool);
     ctx.pool = pool;
     ctx.alg = ALG_APMD5;
@@ -341,10 +362,10 @@ int main(int argc, const char * const ar
      * Any error message text is returned in the record buffer, since
      * the mkrecord() routine doesn't have access to argv[].
      */
-    if (!(mask & APHTP_DELUSER)) {
+    if ((mask & (APHTP_DELUSER|APHTP_VERIFY)) == 0) {
         i = mkrecord(&ctx, user);
         if (i != 0) {
-            apr_file_printf(errfile, "%s: %s" NL, argv[0], errstr);
+            apr_file_printf(errfile, "%s: %s" NL, argv[0], ctx.errstr);
             exit(i);
         }
         if (mask & APHTP_NOFILE) {
@@ -353,21 +374,23 @@ int main(int argc, const char * const ar
         }
     }
 
-    /*
-     * We can access the files the right way, and we have a record
-     * to add or update.  Let's do it..
-     */
-    if (apr_temp_dir_get((const char**)&dirname, pool) != APR_SUCCESS) {
-        apr_file_printf(errfile, "%s: could not determine temp dir" NL,
-                        argv[0]);
-        exit(ERR_FILEPERM);
-    }
-    dirname = apr_psprintf(pool, "%s/%s", dirname, tn);
+    if ((mask & APHTP_VERIFY) == 0) {
+        /*
+         * We can access the files the right way, and we have a record
+         * to add or update.  Let's do it..
+         */
+        if (apr_temp_dir_get((const char**)&dirname, pool) != APR_SUCCESS) {
+            apr_file_printf(errfile, "%s: could not determine temp dir" NL,
+                            argv[0]);
+            exit(ERR_FILEPERM);
+        }
+        dirname = apr_psprintf(pool, "%s/%s", dirname, tn);
 
-    if (apr_file_mktemp(&ftemp, dirname, 0, pool) != APR_SUCCESS) {
-        apr_file_printf(errfile, "%s: unable to create temporary file %s" NL,
-                        argv[0], dirname);
-        exit(ERR_FILEPERM);
+        if (apr_file_mktemp(&ftemp, dirname, 0, pool) != APR_SUCCESS) {
+            apr_file_printf(errfile, "%s: unable to create temporary file %s" NL,
+                            argv[0], dirname);
+            exit(ERR_FILEPERM);
+        }
     }
 
     /*
@@ -418,33 +441,59 @@ int main(int argc, const char * const ar
                 continue;
             }
             else {
-                if (!(mask & APHTP_DELUSER)) {
-                    /* We found the user we were looking for.
-                     * Add him to the file.
-                    */
-                    apr_file_printf(errfile, "Updating ");
-                    putline(ftemp, ctx.out);
-                    found++;
+                /* We found the user we were looking for */
+                found++;
+                if ((mask & APHTP_DELUSER)) {
+                    /* Delete entry from the file */
+                    apr_file_printf(errfile, "Deleting ");
+                }
+                else if ((mask & APHTP_VERIFY)) {
+                    /* Verify */
+                    char *hash = colon + 1;
+                    size_t len;
+
+                    len = strcspn(hash, "\r\n");
+                    if (len == 0) {
+                        apr_file_printf(errfile, "Empty hash for user %s" NL,
+                                        user);
+                        exit(ERR_INVALID);
+                    }
+                    hash[len] = '\0';
+
+                    i = verify(&ctx, hash);
+                    if (i != 0) {
+                        apr_file_printf(errfile, "%s" NL, ctx.errstr);
+                        exit(i);
+                    }
                 }
                 else {
-                    /* We found the user we were looking for.
-                     * Delete them from the file.
-                     */
-                    apr_file_printf(errfile, "Deleting ");
-                    found++;
+                    /* Update entry */
+                    apr_file_printf(errfile, "Updating ");
+                    putline(ftemp, ctx.out);
                 }
             }
         }
         apr_file_close(fpw);
     }
-    if (!found && !(mask & APHTP_DELUSER)) {
-        apr_file_printf(errfile, "Adding ");
-        putline(ftemp, ctx.out);
+    if (!found) {
+        if (mask & APHTP_DELUSER) {
+            apr_file_printf(errfile, "User %s not found" NL, user);
+            exit(0);
+        }
+        else if (mask & APHTP_VERIFY) {
+            apr_file_printf(errfile, "User %s not found" NL, user);
+            exit(ERR_BADUSER);
+        }
+        else {
+            apr_file_printf(errfile, "Adding ");
+            putline(ftemp, ctx.out);
+        }
     }
-    else if (!found && (mask & APHTP_DELUSER)) {
-        apr_file_printf(errfile, "User %s not found" NL, user);
+    if (mask & APHTP_VERIFY) {
+        apr_file_printf(errfile, "Password for user %s correct." NL, user);
         exit(0);
     }
+
     apr_file_printf(errfile, "password for user %s" NL, user);
 
     /* The temporary file has all the data, just copy it to the new location.
