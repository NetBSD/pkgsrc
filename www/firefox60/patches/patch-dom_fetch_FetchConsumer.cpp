$NetBSD: patch-dom_fetch_FetchConsumer.cpp,v 1.1 2018/06/28 14:04:10 ryoon Exp $

--- dom/fetch/FetchConsumer.cpp.orig	2018-05-03 16:58:26.000000000 +0000
+++ dom/fetch/FetchConsumer.cpp
@@ -616,7 +616,7 @@ FetchBodyConsumer<Derived>::ContinueCons
   RefPtr<Promise> localPromise = mConsumePromise.forget();
 
   RefPtr<FetchBodyConsumer<Derived>> self = this;
-  auto autoReleaseObject = mozilla::MakeScopeExit([&] {
+  auto autoReleaseObject = mozilla::MakeScopeExit([self] {
     self->ReleaseObject();
   });
 
