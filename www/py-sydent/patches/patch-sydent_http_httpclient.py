$NetBSD: patch-sydent_http_httpclient.py,v 1.1 2023/08/29 14:15:01 manu Exp $

--- sydent/http/httpclient.py.orig
+++ sydent/http/httpclient.py
@@ -16,9 +16,9 @@
 
 import json
 import logging
 
-from StringIO import StringIO
+from io import StringIO
 from twisted.internet import defer, reactor
 from twisted.web.client import FileBodyProducer, Agent
 from twisted.web.http_headers import Headers
 
