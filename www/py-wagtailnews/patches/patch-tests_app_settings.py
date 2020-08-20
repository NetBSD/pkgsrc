$NetBSD: patch-tests_app_settings.py,v 1.1 2020/08/20 11:19:18 joerg Exp $

aefb23c2eaeb64ff9313fba8893fdb9d516219cd

--- tests/app/settings.py.orig	2020-08-19 23:58:44.261039842 +0000
+++ tests/app/settings.py
@@ -29,6 +29,7 @@ INSTALLED_APPS = [
     'django.contrib.admin',
     'django.contrib.auth',
     'django.contrib.contenttypes',
+    'django.contrib.messages',
     'django.contrib.sessions',
     'django.contrib.staticfiles',
 ]
@@ -60,8 +61,6 @@ MIDDLEWARE = [
     'django.contrib.auth.middleware.AuthenticationMiddleware',
     'django.contrib.messages.middleware.MessageMiddleware',
     'django.middleware.clickjacking.XFrameOptionsMiddleware',
-
-    'wagtail.core.middleware.SiteMiddleware',
 ]
 
 TEMPLATES = [
