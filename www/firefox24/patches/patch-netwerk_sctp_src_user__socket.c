$NetBSD: patch-netwerk_sctp_src_user__socket.c,v 1.1 2013/11/03 04:52:00 ryoon Exp $

--- netwerk/sctp/src/user_socket.c.orig	2013-06-17 22:13:23.000000000 +0000
+++ netwerk/sctp/src/user_socket.c
@@ -1104,8 +1104,13 @@ userspace_sctp_recvmsg(struct socket *so
 		    (struct sctp_sndrcvinfo *)sinfo, 1);
 
 	if (error) {
+#if defined(__Userspace_os_NetBSD)
+		if (auio.uio_resid != (int)ulen && (
+		    error == EINTR || error == EWOULDBLOCK))
+#else
 		if (auio.uio_resid != (int)ulen && (error == ERESTART ||
 		    error == EINTR || error == EWOULDBLOCK))
+#endif
 			error = 0;
 		}
 	if ((fromlenp != NULL) && (fromlen > 0) && (from != NULL)) {
@@ -1193,7 +1198,11 @@ usrsctp_recvv(struct socket *so,
 		    (struct sctp_sndrcvinfo *)&seinfo, 1);
 	if (errno) {
 		if (auio.uio_resid != (int)ulen &&
+#if defined(__Userspace_os_NetBSD)
+		    (errno == EINTR || errno == EWOULDBLOCK)) {
+#else
 		    (errno == ERESTART || errno == EINTR || errno == EWOULDBLOCK)) {
+#endif
 			errno = 0;
 		}
 	}
@@ -2143,7 +2152,11 @@ int user_connect(struct socket *so, stru
 		error = pthread_cond_wait(SOCK_COND(so), SOCK_MTX(so));
 #endif
 		if (error) {
+#if defined(__Userspace_os_NetBSD)
+			if (error == EINTR)
+#else
 			if (error == EINTR || error == ERESTART)
+#endif
 				interrupted = 1;
 			break;
 		}
@@ -2157,8 +2170,10 @@ int user_connect(struct socket *so, stru
 bad:
 	if (!interrupted)
 		so->so_state &= ~SS_ISCONNECTING;
+#if !defined(__Userspace_os_NetBSD)
 	if (error == ERESTART)
 		error = EINTR;
+#endif
 done1:
 	return (error);
 }
