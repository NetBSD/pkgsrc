$NetBSD: patch-README.rst,v 1.2 2017/05/31 08:36:33 adam Exp $

Avoid UTF-8 characters to let setup.py run in ASCII locale.
https://github.com/Runscope/httpbin/issues/269

--- README.rst.orig	2016-08-15 11:29:46.000000000 +0000
+++ README.rst
@@ -41,8 +41,8 @@ Endpoint                                
 `/basic-auth/:user/:passwd`_             Challenges HTTPBasic Auth.
 `/hidden-basic-auth/:user/:passwd`_      404'd BasicAuth.
 `/digest-auth/:qop/:user/:passwd`_       Challenges HTTP Digest Auth.
-`/stream/:n`_                            Streams *n* – 100 lines.
-`/delay/:n`_                             Delays responding for *n* – 10 seconds.
+`/stream/:n`_                            Streams *n* -- 100 lines.
+`/delay/:n`_                             Delays responding for *n* -- 10 seconds.
 `/drip`_                                 Drips up to 10MB data over a duration after an optional initial delay, then (optionally) returns with the given status code.
 `/range/:n`_                             Streams *n* bytes, and allows specifying a *Range* header to select a subset of the data. Accepts a *chunk\_size* and request *duration* parameter.
 `/html`_                                 Renders an HTML Page.
