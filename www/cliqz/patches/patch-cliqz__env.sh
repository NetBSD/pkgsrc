$NetBSD: patch-cliqz__env.sh,v 1.2 2019/11/17 17:32:23 fox Exp $

Commented out the various wget(1) to prevent http traffic during build
phase.

--- cliqz_env.sh.orig	2018-11-16 08:40:07.000000000 +0000
+++ cliqz_env.sh
@@ -78,9 +78,9 @@ export S3_BUCKET=repository.cliqz.com
 export S3_BUCKET_SERVICE=cliqz-browser-data
 
 # check CQZ_BUILD_ID and try to obtain, if not specified
-if [ -z $CQZ_BUILD_ID ]; then
-  export CQZ_BUILD_ID="`wget -qO- https://$S3_BUCKET/dist/$CQZ_RELEASE_CHANNEL/$CQZ_VERSION/lastbuildid`"
-fi
+#if [ -z $CQZ_BUILD_ID ]; then
+#  export CQZ_BUILD_ID="`wget -qO- https://$S3_BUCKET/dist/$CQZ_RELEASE_CHANNEL/$CQZ_VERSION/lastbuildid`"
+#fi
 
 if [ -z $CQZ_BUILD_ID ]; then
   echo "CQZ_BUILD_ID not specified and can not be obtain from "$S3_BUCKET
@@ -103,6 +103,6 @@ OBJ_DIR=$MOZ_OBJDIR
 SRC_BASE=mozilla-release
 
 # automatic forget tab - start
-wget -O adult-domains.bin https://s3.amazonaws.com/cdn.cliqz.com/browser-f/APT/adult-domains.bin
+#wget -O adult-domains.bin https://s3.amazonaws.com/cdn.cliqz.com/browser-f/APT/adult-domains.bin
 export CQZ_ADULT_DOMAINS_BF=../adult-domains.bin
 # automatic forget tab - end
