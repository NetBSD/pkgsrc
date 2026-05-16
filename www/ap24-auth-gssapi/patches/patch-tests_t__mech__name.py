$NetBSD: patch-tests_t__mech__name.py,v 1.1 2026/05/16 03:47:29 riastradh Exp $

Accept disagreement between mit-krb5 and heimdal of case in
human-readable short mechanism name from gss_inquire_saslname_for_mech.

--- tests/t_mech_name.py.orig	2020-11-30 18:30:59.760815267 +0000
+++ tests/t_mech_name.py
@@ -13,7 +13,9 @@ if __name__ == '__main__':
     if r.status_code != 200:
         raise ValueError('Basic Auth Failed')
 
-    if r.text.rstrip() != 'Basic/krb5':
+    # mit-krb5 returns `krb5'; heimdal returns `KRB5' -- maybe this
+    # should use the SASL name, which is formally registered with IANA
+    if r.text.rstrip().casefold() != 'basic/krb5':
         raise ValueError(
             'GSS_MECH check failed, expected Basic/krb5, got "%s"' %
             r.text.rstrip())
