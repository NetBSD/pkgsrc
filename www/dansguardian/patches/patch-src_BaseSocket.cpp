$NetBSD: patch-src_BaseSocket.cpp,v 1.1 2016/04/20 13:52:24 prlw1 Exp $

Defend against calling select() with nfds >= FD_SETSIZE. PR pkg/50995
https://github.com/e2guardian/e2guardian/issues/119

--- src/BaseSocket.cpp.orig	2012-09-29 20:06:45.000000000 +0000
+++ src/BaseSocket.cpp
@@ -61,6 +61,12 @@ int selectEINTR(int numfds, fd_set * rea
 	timeval exittime;
 	timeval elapsedtime;
 	timeval timeoutcopy;
+
+	if (numfds >= FD_SETSIZE) {
+		syslog(LOG_ERR, "selectEINTR called with numfds (%d) >= FD_SETSIZE (%d)", numfds, FD_SETSIZE);
+		errno = EBADF;
+		return -1;
+	}
 	while (true) {  // using the while as a restart point with continue
 		if (timeout != NULL) {
 			gettimeofday(&entrytime, NULL);
@@ -313,6 +319,9 @@ int BaseSocket::getLine(char *buff, int 
 #endif
 		//if there was a socket error
 		if (bufflen < 0) {
+#ifdef DGDEBUG
+			syslog(LOG_ERR, "getLine recv returned error = %d (%m)\n", errno);
+#endif
 			if (errno == EINTR && (honour_reloadconfig ? !reloadconfig : true)) {
 				continue;
 			}
@@ -423,6 +432,9 @@ int BaseSocket::readFromSocketn(char *bu
 		}
 		rc = recv(sck, buff, cnt, flags);
 		if (rc < 0) {
+#ifdef DGDEBUG
+			syslog(LOG_ERR, "readFromSocketn recv returned error = %d (%m)\n", errno);
+#endif
 			if (errno == EINTR) {
 				continue;
 			}
@@ -473,9 +485,14 @@ int BaseSocket::readFromSocket(char *buf
 	while (true) {
 		rc = recv(sck, buff, cnt, flags);
 		if (rc < 0) {
+#ifdef DGDEBUG
+			syslog(LOG_ERR, "readFromSocket recv returned unhandled? error = %d (%m)\n", errno);
+#endif
 			if (errno == EINTR && (honour_reloadconfig ? !reloadconfig : true)) {
 				continue;
 			}
+			sleep(1);
+			continue;
 		}
 
 		break;
