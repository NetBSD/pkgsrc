$NetBSD: patch-mozilla_xpcom_io_nsMultiplexInputStream.cpp,v 1.1 2013/05/23 13:25:30 ryoon Exp $

--- mozilla/xpcom/io/nsMultiplexInputStream.cpp.orig	2013-05-03 03:08:15.000000000 +0000
+++ mozilla/xpcom/io/nsMultiplexInputStream.cpp
@@ -529,7 +529,7 @@ nsMultiplexInputStream::Seek(int32_t aWh
                     rv = stream->Tell(&avail);
                     NS_ENSURE_SUCCESS(rv, rv);
 
-                    int64_t newPos = streamPos + XPCOM_MIN(avail, std::abs(remaining));
+                    int64_t newPos = streamPos + XPCOM_MIN(avail, (int64_t)std::abs(remaining));
 
                     rv = stream->Seek(NS_SEEK_END, -newPos);
                     NS_ENSURE_SUCCESS(rv, rv);
