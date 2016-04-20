$NetBSD: patch-src_ConnectionHandler.cpp,v 1.2 2016/04/20 13:52:24 prlw1 Exp $

maxuploadsize is a filtergroup setting
informative error messages

--- src/ConnectionHandler.cpp.orig	2012-09-29 20:06:45.000000000 +0000
+++ src/ConnectionHandler.cpp
@@ -555,12 +555,14 @@ void ConnectionHandler::handleConnection
 #ifdef DGDEBUG
 						std::cerr << dbgPeerPort << " -Error connecting to proxy" << std::endl;
 #endif
-						syslog(LOG_ERR, "Error connecting to proxy");
+						syslog(LOG_ERR, "Error %d (%m) connecting to proxy %s:%d by client %s", errno, o.proxy_ip.c_str(), o.proxy_port, clientip.c_str());
+
 						return;
 					}
 				}
 				catch(std::exception & e) {
 #ifdef DGDEBUG
+					syslog(LOG_ERR, "Exception while creating proxysock to proxy %s:%d by client %s", o.proxy_ip.c_str(), o.proxy_port, clientip.c_str());
 					std::cerr << dbgPeerPort << " -exception while creating proxysock: " << e.what() << std::endl;
 #endif
 				}
@@ -1598,14 +1600,14 @@ void ConnectionHandler::handleConnection
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
