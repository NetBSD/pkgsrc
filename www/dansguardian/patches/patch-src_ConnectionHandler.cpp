$NetBSD: patch-src_ConnectionHandler.cpp,v 1.1 2015/09/03 11:55:40 sborrill Exp $
maxuploadsize is a filtergroup setting

--- src/ConnectionHandler.cpp.orig	2015-09-03 12:05:59.000000000 +0100
+++ src/ConnectionHandler.cpp	2015-09-03 12:06:56.000000000 +0100
@@ -1598,14 +1598,14 @@
 				// Check for POST upload size blocking, unless request is an exception
 				// MIME type test is just an approximation, but probably good enough
 				if (!isbypass && !isexception
-					&& ((o.max_upload_size >= 0) && (cl > o.max_upload_size))
+					&& ((o.fg[filtergroup]->max_upload_size >= 0) && (cl > o.fg[filtergroup]->max_upload_size))
 					&& multipart)
 				{
 #ifdef DGDEBUG
 					std::cout << dbgPeerPort << " -Detected POST upload violation by Content-Length header - discarding rest of POST data..." << std::endl;
 #endif
 					header.discard(&peerconn);
-					checkme.whatIsNaughty = o.max_upload_size == 0 ? o.language_list.getTranslation(700) : o.language_list.getTranslation(701);
+					checkme.whatIsNaughty = o.fg[filtergroup]->max_upload_size == 0 ? o.language_list.getTranslation(700) : o.language_list.getTranslation(701);
 					// Web upload is banned.
 					checkme.whatIsNaughtyLog = checkme.whatIsNaughty;
 					checkme.whatIsNaughtyCategories = "Web upload";
