$NetBSD: patch-go.mod,v 1.1 2026/06/23 11:34:17 drixter Exp $

Use experimental patch sqlite v1.52.1-0.20260614085003-e62c32f2abc6 for NetBSD
https://gitlab.com/cznic/sqlite/-/work_items/246#note_3456840891

--- go.mod.orig	2026-06-15 16:42:43.042996144 +0000
+++ go.mod
@@ -32,7 +32,7 @@ require (
 	k8s.io/api v0.35.1
 	k8s.io/apimachinery v0.35.1
 	k8s.io/client-go v0.35.1
-	modernc.org/sqlite v1.39.0
+	modernc.org/sqlite v1.52.1-0.20260614085003-e62c32f2abc6 
 	nhooyr.io/websocket v1.8.7
 )
 
@@ -74,7 +74,7 @@ require (
 	github.com/muesli/cancelreader v0.2.2 // indirect
 	github.com/munnerz/goautoneg v0.0.0-20191010083416-a7dc8b61c822 // indirect
 	github.com/mxk/go-flowrate v0.0.0-20140419014527-cca7078d478f // indirect
-	github.com/ncruces/go-strftime v0.1.9 // indirect
+	github.com/ncruces/go-strftime v1.0.0 // indirect
 	github.com/pb33f/jsonpath v0.8.1 // indirect
 	github.com/pb33f/ordered-map/v2 v2.3.0 // indirect
 	github.com/remyoudompheng/bigfft v0.0.0-20230129092748-24d4a6f8daec // indirect
@@ -90,8 +90,8 @@ require (
 	go.yaml.in/yaml/v3 v3.0.4 // indirect
 	golang.org/x/exp v0.0.0-20250620022241-b7579e27df2b // indirect
 	golang.org/x/oauth2 v0.30.0 // indirect
-	golang.org/x/sync v0.19.0 // indirect
-	golang.org/x/sys v0.38.0 // indirect
+	golang.org/x/sync v0.20.0 // indirect
+	golang.org/x/sys v0.44.0 // indirect
 	golang.org/x/term v0.37.0 // indirect
 	golang.org/x/text v0.31.0 // indirect
 	golang.org/x/time v0.9.0 // indirect
@@ -102,7 +102,7 @@ require (
 	k8s.io/klog/v2 v2.130.1 // indirect
 	k8s.io/kube-openapi v0.0.0-20250910181357-589584f1c912 // indirect
 	k8s.io/utils v0.0.0-20251002143259-bc988d571ff4 // indirect
-	modernc.org/libc v1.66.3 // indirect
+	modernc.org/libc v1.73.3 // indirect
 	modernc.org/mathutil v1.7.1 // indirect
 	modernc.org/memory v1.11.0 // indirect
 	sigs.k8s.io/json v0.0.0-20250730193827-2d320260d730 // indirect
