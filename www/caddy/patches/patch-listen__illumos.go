$NetBSD: patch-listen__illumos.go,v 1.2 2023/02/17 15:47:09 bsiegert Exp $

SunOS platforms do not have SO_REUSEPORT.

--- listen_illumos.go.orig	2023-02-17 15:09:59.805523778 +0000
+++ listen_illumos.go
@@ -15,7 +15,7 @@
 // TODO: Go 1.19 introduced the "unix" build tag. We have to support Go 1.18 until Go 1.20 is released.
 // When Go 1.19 is our minimum, remove this build tag, since "_unix" in the filename will do this.
 // (see also change needed in listen.go)
-//go:build aix || android || darwin || dragonfly || freebsd || hurd || illumos || ios || linux || netbsd || openbsd || solaris
+//go:build illumos || solaris
 
 package caddy
 
@@ -26,9 +26,6 @@ import (
 	"net"
 	"sync/atomic"
 	"syscall"
-
-	"go.uber.org/zap"
-	"golang.org/x/sys/unix"
 )
 
 // reuseUnixSocket copies and reuses the unix domain socket (UDS) if we already
@@ -96,23 +93,7 @@ func listenTCPOrUnix(ctx context.Context
 				return err
 			}
 		}
-		return reusePort(network, address, c)
-	}
-	return config.Listen(ctx, network, address)
-}
-
-// reusePort sets SO_REUSEPORT. Ineffective for unix sockets.
-func reusePort(network, address string, conn syscall.RawConn) error {
-	if IsUnixNetwork(network) {
 		return nil
 	}
-	return conn.Control(func(descriptor uintptr) {
-		if err := unix.SetsockoptInt(int(descriptor), unix.SOL_SOCKET, unix.SO_REUSEPORT, 1); err != nil {
-			Log().Error("setting SO_REUSEPORT",
-				zap.String("network", network),
-				zap.String("address", address),
-				zap.Uintptr("descriptor", descriptor),
-				zap.Error(err))
-		}
-	})
+	return config.Listen(ctx, network, address)
 }
