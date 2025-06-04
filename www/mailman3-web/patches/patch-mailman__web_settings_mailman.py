$NetBSD: patch-mailman__web_settings_mailman.py,v 1.2 2025/06/04 11:17:44 markd Exp $

https://gitlab.com/mailman/mailman-web/-/commit/3713b55989fbf0e5e79a6df64fd41cfdd3353262
https://gitlab.com/mailman/mailman-web/-/commit/1af9f7c900c310b60ac17ae71e0cbb68ee97c0b9
  for django-allauth >= 65.5

configure paths

--- mailman_web/settings/mailman.py.orig	2024-03-07 08:49:37.048697200 +0000
+++ mailman_web/settings/mailman.py
@@ -28,8 +28,8 @@ DEFAULT_FROM_EMAIL = 'postorius@localhos
 
 
 #: Django Allauth
-ACCOUNT_AUTHENTICATION_METHOD = "username_email"
-ACCOUNT_EMAIL_REQUIRED = True
+ACCOUNT_LOGIN_METHODS = {'email', 'username'}
+ACCOUNT_SIGNUP_FIELDS = ['username*', 'email*', 'password1*', 'password2*']
 ACCOUNT_EMAIL_VERIFICATION = "mandatory"
 ACCOUNT_UNIQUE_EMAIL = True
 
@@ -93,7 +93,7 @@ AUTHENTICATION_BACKENDS = (
 HAYSTACK_CONNECTIONS = {
     'default': {
         'ENGINE': 'haystack.backends.whoosh_backend.WhooshEngine',
-        'PATH': "fulltext_index",
+        'PATH': "@VARBASE@/lib/mailman-web/data/fulltext_index",
         # You can also use the Xapian engine, it's faster and more accurate,
         # but requires another library.
         # http://django-haystack.readthedocs.io/en/v2.4.1/installing_search_engines.html#xapian
