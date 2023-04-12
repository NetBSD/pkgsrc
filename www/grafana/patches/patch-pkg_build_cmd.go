$NetBSD: patch-pkg_build_cmd.go,v 1.4 2023/04/12 19:26:27 adam Exp $

Use the same go binary as the one used to build.

--- pkg/build/cmd.go.orig	2023-03-16 23:56:52.000000000 +0000
+++ pkg/build/cmd.go
@@ -141,7 +141,7 @@ func setup(goos string) {
 		args = append(args, "-buildmode=exe")
 	}
 	args = append(args, "./pkg/cmd/grafana-server")
-	runPrint("go", args...)
+	runPrint("@GO@", args...)
 }
 
 func doBuild(binaryName, pkg string, opts BuildOpts) error {
@@ -193,13 +193,13 @@ func doBuild(binaryName, pkg string, opt
 	args = append(args, "-o", binary)
 	args = append(args, pkg)
 
-	runPrint("go", args...)
+	runPrint("@GO@", args...)
 
 	if opts.isDev {
 		return nil
 	}
 
-	runPrint("go", "version")
+	runPrint("@GO@", "version")
 	libcPart = ""
 	if opts.libc != "" {
 		libcPart = fmt.Sprintf("/%s", opts.libc)
