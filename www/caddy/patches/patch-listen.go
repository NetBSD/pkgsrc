$NetBSD: patch-listen.go,v 1.1 2024/05/17 11:38:37 jperkin Exp $

https://github.com/caddyserver/caddy/pull/6021

--- listen.go.orig	2024-05-17 11:30:15.570928551 +0000
+++ listen.go
@@ -12,7 +12,7 @@
 // See the License for the specific language governing permissions and
 // limitations under the License.
 
-//go:build !unix
+//go:build !unix || solaris || illumos
 
 package caddy
 
