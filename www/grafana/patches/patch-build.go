$NetBSD: patch-build.go,v 1.1 2021/03/23 04:16:08 triaxx Exp $

Use the same go binary as the one used to build.

--- build.go.orig	2021-03-18 09:23:36.000000000 +0000
+++ build.go
@@ -224,7 +224,7 @@ func setup() {
 		args = append(args, "-buildmode=exe")
 	}
 	args = append(args, "./pkg/cmd/grafana-server")
-	runPrint("go", args...)
+	runPrint("@GO@", args...)
 }
 
 func printGeneratedVersion() {
@@ -238,7 +238,7 @@ func test(pkg string) {
 		args = append(args, "-buildmode=exe")
 	}
 	args = append(args, pkg)
-	runPrint("go", args...)
+	runPrint("@GO@", args...)
 }
 
 func doBuild(binaryName, pkg string, tags []string) {
@@ -276,7 +276,7 @@ func doBuild(binaryName, pkg string, tag
 
 	if !isDev {
 		setBuildEnv()
-		runPrint("go", "version")
+		runPrint("@GO@", "version")
 		libcPart := ""
 		if libc != "" {
 			libcPart = fmt.Sprintf("/%s", libc)
@@ -284,7 +284,7 @@ func doBuild(binaryName, pkg string, tag
 		fmt.Printf("Targeting %s/%s%s\n", goos, goarch, libcPart)
 	}
 
-	runPrint("go", args...)
+	runPrint("@GO@", args...)
 
 	if !isDev {
 		// Create an md5 checksum of the binary, to be included in the archive for
