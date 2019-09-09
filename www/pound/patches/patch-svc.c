$NetBSD: patch-svc.c,v 1.1 2019/09/09 09:08:08 nia Exp $

[PATCH] Support for Openssl 1.1
https://github.com/graygnuorg/pound/commit/a2c9dde4d055ea8942afb150b7fc3a807d4e5d60.patch

--- svc.c.orig	2018-05-11 10:16:05.000000000 +0000
+++ svc.c
@@ -27,10 +27,17 @@
 
 #include    "pound.h"
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+# define TABNODE_GET_DOWN_LOAD(t) lh_TABNODE_get_down_load(t)
+# define TABNODE_SET_DOWN_LOAD(t,n) lh_TABNODE_set_down_load(t,n)
+#else
 #ifndef LHASH_OF
 #define LHASH_OF(x) LHASH
 #define CHECKED_LHASH_OF(type, h) h
 #endif
+# define TABNODE_GET_DOWN_LOAD(t) (CHECKED_LHASH_OF(TABNODE, t)->down_load)
+# define TABNODE_SET_DOWN_LOAD(t,n) (CHECKED_LHASH_OF(TABNODE, t)->down_load = n)
+#endif
 
 /*
  * Add a new key/content pair to a hash table
@@ -58,7 +65,9 @@ t_add(LHASH_OF(TABNODE) *const tab, cons
     }
     memcpy(t->content, content, cont_len);
     t->last_acc = time(NULL);
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+    if((old = lh_TABNODE_insert(tab, t)) != NULL) {
+#elif OPENSSL_VERSION_NUMBER >= 0x10000000L
     if((old = LHM_lh_insert(TABNODE, tab, t)) != NULL) {
 #else
     if((old = (TABNODE *)lh_insert(tab, t)) != NULL) {
@@ -82,7 +91,9 @@ t_find(LHASH_OF(TABNODE) *const tab, cha
     TABNODE t, *res;
 
     t.key = key;
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+    if((res = lh_TABNODE_retrieve(tab, &t)) != NULL) {
+#elif OPENSSL_VERSION_NUMBER >= 0x10000000L
     if((res = (TABNODE *)LHM_lh_retrieve(TABNODE, tab, &t)) != NULL) {
 #else
     if((res = (TABNODE *)lh_retrieve(tab, &t)) != NULL) {
@@ -102,7 +113,9 @@ t_remove(LHASH_OF(TABNODE) *const tab, c
     TABNODE t, *res;
 
     t.key = key;
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+    if((res = lh_TABNODE_delete(tab, &t)) != NULL) {    
+#elif OPENSSL_VERSION_NUMBER >= 0x10000000L
     if((res = LHM_lh_delete(TABNODE, tab, &t)) != NULL) {
 #else
     if((res = (TABNODE *)lh_delete(tab, &t)) != NULL) {
@@ -127,7 +140,9 @@ t_old_doall_arg(TABNODE *t, ALL_ARG *a)
     TABNODE *res;
 
     if(t->last_acc < a->lim)
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+        if((res = lh_TABNODE_delete(a->tab, t)) != NULL) {	    
+#elif OPENSSL_VERSION_NUMBER >= 0x10000000L
         if((res = LHM_lh_delete(TABNODE, a->tab, t)) != NULL) {
 #else
         if((res = lh_delete(a->tab, t)) != NULL) {
@@ -145,6 +160,10 @@ IMPLEMENT_LHASH_DOALL_ARG_FN(t_old, TABN
 IMPLEMENT_LHASH_DOALL_ARG_FN(t_old, TABNODE *, ALL_ARG *)
 #endif
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+IMPLEMENT_LHASH_DOALL_ARG(TABNODE,ALL_ARG);
+#endif
+
 /*
  * Expire all old nodes
  */
@@ -156,14 +175,16 @@ t_expire(LHASH_OF(TABNODE) *const tab, c
 
     a.tab = tab;
     a.lim = lim;
-    down_load = CHECKED_LHASH_OF(TABNODE, tab)->down_load;
-    CHECKED_LHASH_OF(TABNODE, tab)->down_load = 0;
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+    down_load = TABNODE_GET_DOWN_LOAD(tab);
+    TABNODE_SET_DOWN_LOAD(tab, 0);
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+    lh_TABNODE_doall_ALL_ARG(tab, t_old_doall_arg, &a);
+#elif OPENSSL_VERSION_NUMBER >= 0x10000000L
     LHM_lh_doall_arg(TABNODE, tab, LHASH_DOALL_ARG_FN(t_old), ALL_ARG, &a);
 #else
     lh_doall_arg(tab, LHASH_DOALL_ARG_FN(t_old), &a);
 #endif
-    CHECKED_LHASH_OF(TABNODE, tab)->down_load = down_load;
+    TABNODE_SET_DOWN_LOAD(tab, down_load);
     return;
 }
 
@@ -173,7 +194,9 @@ t_cont_doall_arg(TABNODE *t, ALL_ARG *ar
     TABNODE *res;
 
     if(memcmp(t->content, arg->content, arg->cont_len) == 0)
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+        if((res = lh_TABNODE_delete(arg->tab, t)) != NULL) {
+#elif OPENSSL_VERSION_NUMBER >= 0x10000000L
         if((res = LHM_lh_delete(TABNODE, arg->tab, t)) != NULL) {
 #else
         if((res = lh_delete(arg->tab, t)) != NULL) {
@@ -203,15 +226,16 @@ t_clean(LHASH_OF(TABNODE) *const tab, vo
     a.tab = tab;
     a.content = content;
     a.cont_len = cont_len;
-    down_load = CHECKED_LHASH_OF(TABNODE, tab)->down_load;
-    CHECKED_LHASH_OF(TABNODE, tab)->down_load = 0;
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+    down_load = TABNODE_GET_DOWN_LOAD(tab);
+    TABNODE_SET_DOWN_LOAD(tab, 0);
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+    lh_TABNODE_doall_ALL_ARG(tab, t_cont_doall_arg, &a);
+#elif OPENSSL_VERSION_NUMBER >= 0x10000000L
     LHM_lh_doall_arg(TABNODE, tab, LHASH_DOALL_ARG_FN(t_cont), ALL_ARG, &a);
 #else
     lh_doall_arg(tab, LHASH_DOALL_ARG_FN(t_cont), &a);
 #endif
-    CHECKED_LHASH_OF(TABNODE, tab)->down_load = down_load;
-    return;
+    TABNODE_SET_DOWN_LOAD(tab, down_load);
 }
 
 /*
@@ -1259,6 +1283,31 @@ RSA_tmp_callback(/* not used */SSL *ssl,
     return res;
 }
 
+static int
+generate_key(RSA **ret_rsa, unsigned long bits)
+{
+#if OPENSSL_VERSION_NUMBER > 0x00908000L
+    int rc = 0;
+    RSA *rsa;
+
+    rsa = RSA_new();
+    if (rsa) {
+	BIGNUM *bne = BN_new();
+	if (BN_set_word(bne, RSA_F4))
+	    rc = RSA_generate_key_ex(rsa, bits, bne, NULL);
+	BN_free(bne);
+	if (rc)
+	    *ret_rsa = rsa;
+	else
+	    RSA_free(rsa);
+    }
+    return rc;
+#else
+    *ret_rsa = RSA_generate_key(bits, RSA_F4, NULL, NULL);
+    return *ret_rsa != NULL;
+#endif
+}
+
 /*
  * Periodically regenerate ephemeral RSA keys
  * runs every T_RSA_KEYS seconds
@@ -1271,8 +1320,9 @@ do_RSAgen(void)
     RSA *t_RSA1024_keys[N_RSA_KEYS];
 
     for(n = 0; n < N_RSA_KEYS; n++) {
-        t_RSA512_keys[n] = RSA_generate_key(512, RSA_F4, NULL, NULL);
-        t_RSA1024_keys[n] = RSA_generate_key(1024, RSA_F4, NULL, NULL);
+        /* FIXME: Error handling */
+        generate_key(&t_RSA512_keys[n], 512);
+	generate_key(&t_RSA1024_keys[n], 1024);
     }
     if(ret_val = pthread_mutex_lock(&RSA_mut))
         logmsg(LOG_WARNING, "thr_RSAgen() lock: %s", strerror(ret_val));
@@ -1326,11 +1376,11 @@ init_timer(void)
      * Pre-generate ephemeral RSA keys
      */
     for(n = 0; n < N_RSA_KEYS; n++) {
-        if((RSA512_keys[n] = RSA_generate_key(512, RSA_F4, NULL, NULL)) == NULL) {
+        if(!generate_key(&RSA512_keys[n], 512)) {
             logmsg(LOG_WARNING,"RSA_generate(%d, 512) failed", n);
             return;
         }
-        if((RSA1024_keys[n] = RSA_generate_key(1024, RSA_F4, NULL, NULL)) == NULL) {
+        if(!generate_key(&RSA1024_keys[n], 1024)) {
             logmsg(LOG_WARNING,"RSA_generate(%d, 1024) failed", n);
             return;
         }
@@ -1417,6 +1467,10 @@ IMPLEMENT_LHASH_DOALL_ARG_FN(t_dump, TAB
 IMPLEMENT_LHASH_DOALL_ARG_FN(t_dump, TABNODE *, DUMP_ARG *)
 #endif
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+IMPLEMENT_LHASH_DOALL_ARG(TABNODE,DUMP_ARG);
+#endif
+	
 /*
  * write sessions to the control socket
  */
@@ -1427,7 +1481,9 @@ dump_sess(const int control_sock, LHASH_
 
     a.control_sock = control_sock;
     a.backends = backends;
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+    lh_TABNODE_doall_DUMP_ARG(sess, t_dump_doall_arg, &a);
+#elif OPENSSL_VERSION_NUMBER >= 0x10000000L
     LHM_lh_doall_arg(TABNODE, sess, LHASH_DOALL_ARG_FN(t_dump), DUMP_ARG, &a);
 #else
     lh_doall_arg(sess, LHASH_DOALL_ARG_FN(t_dump), &a);
@@ -1661,6 +1717,13 @@ thr_control(void *arg)
     }
 }
 
+#ifndef SSL3_ST_SR_CLNT_HELLO_A
+# define SSL3_ST_SR_CLNT_HELLO_A (0x110|SSL_ST_ACCEPT)
+#endif
+#ifndef SSL23_ST_SR_CLNT_HELLO_A
+# define SSL23_ST_SR_CLNT_HELLO_A (0x210|SSL_ST_ACCEPT)
+#endif
+		
 void
 SSLINFO_callback(const SSL *ssl, int where, int rc)
 {
