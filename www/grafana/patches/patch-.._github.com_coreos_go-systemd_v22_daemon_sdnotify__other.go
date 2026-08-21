$NetBSD: patch-.._github.com_coreos_go-systemd_v22_daemon_sdnotify__other.go,v 1.1 2026/08/21 18:04:06 tnn Exp $

unix.CLOCK_MONOTONIC undefined on at least NetBSD/aarch64.
Should file a bug with golang.org/x/sys/unix upstream about this.

--- ../github.com/coreos/go-systemd/v22/daemon/sdnotify_other.go.orig	2026-08-18 21:51:55.805551696 +0000
+++ ../github.com/coreos/go-systemd/v22/daemon/sdnotify_other.go
@@ -12,7 +12,7 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
-//go:build !unix
+//go:build !unix || netbsd
 
 package daemon
 
