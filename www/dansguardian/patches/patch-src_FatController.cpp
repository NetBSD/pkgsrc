$NetBSD: patch-src_FatController.cpp,v 1.1 2016/04/20 13:52:24 prlw1 Exp $

Defend against calling select() with nfds >= FD_SETSIZE.
PR pkg/50995

--- src/FatController.cpp.orig	2012-09-29 20:06:45.000000000 +0000
+++ src/FatController.cpp
@@ -1473,6 +1473,13 @@ int url_list_listener(bool logconerror)
 	std::cout << "url ipcsockfd:" << ipcsockfd << std::endl;
 #endif
 
+	if (ipcsockfd + 1 >= FD_SETSIZE) {
+		syslog(LOG_ERR, "ipcsockfd+1 (%d) >= FD_SETSIZE (%d)", ipcsockfd+1, FD_SETSIZE);
+		delete[]logline;
+		urllistsock.close();
+		return 1;
+        }
+
 	fd_set fdSet;  // our set of fds (only 1) that select monitors for us
 	fd_set fdcpy;  // select modifes the set so we need to use a copy
 	FD_ZERO(&fdSet);  // clear the set
@@ -1597,6 +1604,13 @@ int ip_list_listener(std::string stat_lo
 
 	ipcsockfd = iplistsock.getFD();
 
+	if (ipcsockfd + 1 >= FD_SETSIZE) {
+		syslog(LOG_ERR, "ipcsockfd+1 (%d) >= FD_SETSIZE (%d)", ipcsockfd+1, FD_SETSIZE);
+		delete[]inbuff;
+		urllistsock.close();
+		return 1;
+        }
+
 	unsigned long int ip;
 	char reply;
 	struct in_addr inaddr;
