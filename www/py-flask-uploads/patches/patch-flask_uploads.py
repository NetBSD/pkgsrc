$NetBSD: patch-flask_uploads.py,v 1.1 2016/06/01 21:10:39 kleink Exp $

flask.Module, unused, was removed in Flask 0.11.

--- flask_uploads.py.orig	2015-12-17 16:00:07.000000000 +0000
+++ flask_uploads.py
@@ -21,7 +21,7 @@ else:
 import os.path
 import posixpath
 
-from flask import current_app, Module, send_from_directory, abort, url_for
+from flask import current_app, send_from_directory, abort, url_for
 from itertools import chain
 from werkzeug import secure_filename, FileStorage
 
