$NetBSD: patch-config.c,v 1.1 2019/09/09 09:08:08 nia Exp $

[PATCH] Support for Openssl 1.1
https://github.com/graygnuorg/pound/commit/a2c9dde4d055ea8942afb150b7fc3a807d4e5d60.patch

--- config.c.orig	2018-05-11 10:16:05.000000000 +0000
+++ config.c
@@ -174,6 +174,16 @@ conf_fgets(char *buf, const int max)
     }
 }
 
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+# define general_name_string(n) \
+	strndup(ASN1_STRING_get0_data(n->d.dNSName),	\
+	        ASN1_STRING_length(n->d.dNSName) + 1)
+#else
+# define general_name_string(n) \
+	strndup(ASN1_STRING_data(n->d.dNSName),	\
+	       ASN1_STRING_length(n->d.dNSName) + 1)
+#endif
+
 unsigned char **
 get_subjectaltnames(X509 *x509, unsigned int *count)
 {
@@ -194,8 +204,7 @@ get_subjectaltnames(X509 *x509, unsigned
         name = sk_GENERAL_NAME_pop(san_stack);
         switch(name->type) {
             case GEN_DNS:
-                temp[local_count] = strndup(ASN1_STRING_data(name->d.dNSName), ASN1_STRING_length(name->d.dNSName)
-                                    + 1);
+ 	        temp[local_count] = general_name_string(name);
                 if(temp[local_count] == NULL)
                     conf_err("out of memory");
                 local_count++;
@@ -565,7 +574,9 @@ parse_service(const char *svc_name)
     pthread_mutex_init(&res->mut, NULL);
     if(svc_name)
         strncpy(res->name, svc_name, KEY_SIZE);
-#if OPENSSL_VERSION_NUMBER >= 0x10000000L
+#if OPENSSL_VERSION_NUMBER >= 0x10100000L
+    if((res->sessions = lh_TABNODE_new(t_hash, t_cmp)) == NULL)    
+#elif OPENSSL_VERSION_NUMBER >= 0x10000000L
     if((res->sessions = LHM_lh_new(TABNODE, t)) == NULL)
 #else
     if((res->sessions = lh_new(LHASH_HASH_FN(t_hash), LHASH_COMP_FN(t_cmp))) == NULL)
