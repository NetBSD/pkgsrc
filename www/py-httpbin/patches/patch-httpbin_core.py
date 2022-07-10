$NetBSD: patch-httpbin_core.py,v 1.1 2022/07/10 19:52:03 wiz Exp $

Fix compatibility with py-werkzeug>=2.1
https://github.com/postmanlabs/httpbin/issues/673

--- httpbin/core.py.orig	2018-05-08 11:41:03.000000000 +0000
+++ httpbin/core.py
@@ -19,7 +19,7 @@ from flask import Flask, Response, reque
 from six.moves import range as xrange
 from werkzeug.datastructures import WWWAuthenticate, MultiDict
 from werkzeug.http import http_date
-from werkzeug.wrappers import BaseResponse
+from werkzeug.wrappers import Response as BaseResponse
 from werkzeug.http import parse_authorization_header
 from raven.contrib.flask import Sentry
 
