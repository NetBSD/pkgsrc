$NetBSD: patch-binary__database__files_views.py,v 1.1 2020/08/04 01:14:36 joerg Exp $

PR #27

--- binary_database_files/views.py.orig	2020-08-03 18:11:14.391876186 +0000
+++ binary_database_files/views.py
@@ -7,7 +7,7 @@ from django.views.decorators.cache impor
 from django.views.static import serve as django_serve
 
 from binary_database_files.models import File
-
+from binary_database_files import settings as _settings
 
 @cache_control(max_age=86400)
 def serve(request, name):
@@ -15,7 +15,8 @@ def serve(request, name):
     Retrieves the file from the database.
     """
     f = get_object_or_404(File, name=name)
-    f.dump()
+    if _settings.DB_FILES_AUTO_EXPORT_DB_TO_FS:
+        f.dump()
     mimetype = mimetypes.guess_type(name)[0] or "application/octet-stream"
     # Cast to bytes to work around https://code.djangoproject.com/ticket/30294
     response = HttpResponse(bytes(f.content), content_type=mimetype)
