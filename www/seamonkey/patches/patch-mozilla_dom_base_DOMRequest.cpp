$NetBSD: patch-mozilla_dom_base_DOMRequest.cpp,v 1.1 2015/10/07 23:21:07 joerg Exp $

--- mozilla/dom/base/DOMRequest.cpp.orig	2015-09-25 07:36:10.000000000 +0000
+++ mozilla/dom/base/DOMRequest.cpp
@@ -19,7 +19,6 @@ using mozilla::dom::DOMError;
 using mozilla::dom::DOMRequest;
 using mozilla::dom::DOMRequestService;
 using mozilla::dom::DOMCursor;
-using mozilla::dom::Promise;
 using mozilla::dom::AutoJSAPI;
 
 DOMRequest::DOMRequest(nsPIDOMWindow* aWindow)
