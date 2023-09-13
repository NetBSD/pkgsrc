$NetBSD: patch-src_acl_external_kerberos__ldap__group_support__resolv.cc,v 1.1 2023/09/13 07:36:45 taca Exp $

* Use correct format string.

--- src/acl/external/kerberos_ldap_group/support_resolv.cc.orig	2019-07-09 19:05:20.000000000 +0000
+++ src/acl/external/kerberos_ldap_group/support_resolv.cc
@@ -396,7 +396,7 @@ get_ldap_hostname_list(struct main_args 
 #if (SIZEOF_LONG == 8)
         error("%s| %s: ERROR: Inconsistence message length: %ld!=0\n", LogTime(), PROGRAM, buffer + len - p);
 #else
-        error((char *) "%s| %s: ERROR: Inconsistence message length: %d!=0\n", LogTime(), PROGRAM, buffer + len - p);
+        error((char *) "%s| %s: ERROR: Inconsistence message length: %ld!=0\n", LogTime(), PROGRAM, buffer + len - p);
 #endif
         goto finalise;
     }
