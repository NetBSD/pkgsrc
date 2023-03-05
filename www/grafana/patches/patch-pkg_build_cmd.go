$NetBSD: patch-pkg_build_cmd.go,v 1.3 2023/03/05 21:22:45 triaxx Exp $

Use the same go binary as the one used to build.
from: patch-build.go,v 1.1 2021/03/23 04:16:08 triaxx Exp

--- pkg/build/cmd.go.orig	2021-12-06 07:21:15.000000000 +0000
+++ pkg/build/cmd.go
@@ -141,7 +141,7 @@ func setup(goos string) {
 		args = append(args, "-buildmode=exe")
 	}
 	args = append(args, "./pkg/cmd/grafana-server")
-	runPrint("go", args...)
+	runPrint("@GO@", args...)
 }
 
 func doBuild(binaryName, pkg string, opts BuildOpts) error {
@@ -188,7 +188,7 @@ func doBuild(binaryName, pkg string, opt
 	args = append(args, "-o", binary)
 	args = append(args, pkg)
 
-	runPrint("go", args...)
+	runPrint("@GO@", args...)
 
 	if opts.isDev {
 		return nil
@@ -197,7 +197,7 @@ func doBuild(binaryName, pkg string, opt
 	if err := setBuildEnv(opts); err != nil {
 		return err
 	}
-	runPrint("go", "version")
+	runPrint("@GO@", "version")
 	libcPart = ""
 	if opts.libc != "" {
 		libcPart = fmt.Sprintf("/%s", opts.libc)
