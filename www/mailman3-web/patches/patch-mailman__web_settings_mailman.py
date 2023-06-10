$NetBSD: patch-mailman__web_settings_mailman.py,v 1.1 2023/06/10 06:00:53 markd Exp $

configure paths

--- mailman_web/settings/mailman.py.orig	2022-09-10 14:41:36.000000000 +0000
+++ mailman_web/settings/mailman.py
@@ -93,7 +93,7 @@ AUTHENTICATION_BACKENDS = (
 HAYSTACK_CONNECTIONS = {
     'default': {
         'ENGINE': 'haystack.backends.whoosh_backend.WhooshEngine',
-        'PATH': "fulltext_index",
+        'PATH': "@VARBASE@/lib/mailman-web/data/fulltext_index",
         # You can also use the Xapian engine, it's faster and more accurate,
         # but requires another library.
         # http://django-haystack.readthedocs.io/en/v2.4.1/installing_search_engines.html#xapian
