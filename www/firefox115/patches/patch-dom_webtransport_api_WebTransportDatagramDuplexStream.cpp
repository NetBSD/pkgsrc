$NetBSD: patch-dom_webtransport_api_WebTransportDatagramDuplexStream.cpp,v 1.1 2023/09/11 12:33:25 ryoon Exp $

--- dom/webtransport/api/WebTransportDatagramDuplexStream.cpp.orig	2023-04-23 21:17:18.000000000 +0000
+++ dom/webtransport/api/WebTransportDatagramDuplexStream.cpp
@@ -62,7 +62,7 @@ void WebTransportDatagramDuplexStream::S
                                                          ErrorResult& aRv) {
   // https://w3c.github.io/webtransport/#dom-webtransportdatagramduplexstream-incomingmaxage
   // Step 1
-  if (isnan(aMaxAge) || aMaxAge < 0.) {
+  if (std::isnan(aMaxAge) || aMaxAge < 0.) {
     aRv.ThrowRangeError("Invalid IncomingMaxAge");
     return;
   }
@@ -78,7 +78,7 @@ void WebTransportDatagramDuplexStream::S
                                                          ErrorResult& aRv) {
   // https://w3c.github.io/webtransport/#dom-webtransportdatagramduplexstream-outgoingmaxage
   // Step 1
-  if (isnan(aMaxAge) || aMaxAge < 0.) {
+  if (std::isnan(aMaxAge) || aMaxAge < 0.) {
     aRv.ThrowRangeError("Invalid OutgoingMaxAge");
     return;
   }
@@ -94,7 +94,7 @@ void WebTransportDatagramDuplexStream::S
     double aWaterMark, ErrorResult& aRv) {
   // https://w3c.github.io/webtransport/#dom-webtransportdatagramduplexstream-incominghighwatermark
   // Step 1
-  if (isnan(aWaterMark) || aWaterMark < 0.) {
+  if (std::isnan(aWaterMark) || aWaterMark < 0.) {
     aRv.ThrowRangeError("Invalid OutgoingMaxAge");
     return;
   }
@@ -110,7 +110,7 @@ void WebTransportDatagramDuplexStream::S
     double aWaterMark, ErrorResult& aRv) {
   // https://w3c.github.io/webtransport/#dom-webtransportdatagramduplexstream-outgoinghighwatermark
   // Step 1
-  if (isnan(aWaterMark) || aWaterMark < 0.) {
+  if (std::isnan(aWaterMark) || aWaterMark < 0.) {
     aRv.ThrowRangeError("Invalid OutgoingHighWaterMark");
     return;
   }
