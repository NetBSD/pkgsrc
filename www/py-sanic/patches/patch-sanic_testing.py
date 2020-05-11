$NetBSD: patch-sanic_testing.py,v 1.1 2020/05/11 05:34:07 adam Exp $

Fix for newer httpx.
https://github.com/huge-success/sanic/pull/1806

--- sanic/testing.py.orig	2020-05-10 18:16:45.000000000 +0000
+++ sanic/testing.py
@@ -185,7 +185,7 @@ async def app_call_with_return(self, sco
     return await asgi_app()
 
 
-class SanicASGIDispatch(httpx.dispatch.ASGIDispatch):
+class SanicASGIDispatch(httpx.ASGIDispatch):
     pass
 
 
