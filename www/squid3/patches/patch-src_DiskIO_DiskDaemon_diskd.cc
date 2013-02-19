$NetBSD: patch-src_DiskIO_DiskDaemon_diskd.cc,v 1.1 2013/02/19 19:22:45 markd Exp $

------------------------------------------------------------
revno: 12497
revision-id: squid3@treenet.co.nz-20130214091437-0kf8k09qf1sg8ker
parent: squid3@treenet.co.nz-20130214091347-nkfdacfkt0urnwq4
fixes bug(s): http://bugs.squid-cache.org/show_bug.cgi?id=3763
committer: Amos Jeffries <squid3@treenet.co.nz>
branch nick: 3.3
timestamp: Thu 2013-02-14 02:14:37 -0700
message:
  Bug 3763: diskd Error: no filename in shm buffer
------------------------------------------------------------
# Bazaar merge directive format 2 (Bazaar 0.90)
# revision_id: squid3@treenet.co.nz-20130214091437-0kf8k09qf1sg8ker
# target_branch: http://bzr.squid-cache.org/bzr/squid3/3.3
# testament_sha1: 6098b2dbc1bcd0230017a40b0ebd75e375148fec
# timestamp: 2013-02-14 09:15:28 +0000
# source_branch: http://bzr.squid-cache.org/bzr/squid3/3.3
# base_revision_id: squid3@treenet.co.nz-20130214091347-\
#   nkfdacfkt0urnwq4
# 
# Begin patch
=== modified file 'src/DiskIO/DiskDaemon/diskd.cc'
--- src/DiskIO/DiskDaemon/diskd.cc	2013-01-02 10:09:54 +0000
+++ src/DiskIO/DiskDaemon/diskd.cc	2013-02-14 09:14:37 +0000
@@ -264,7 +264,7 @@
 
     if (s->shm_offset > -1)
         buf = shmbuf + s->shm_offset;
-    else {
+    else if (r->mtype != _MQD_CLOSE) {
         fprintf(stderr, "%d UNLNK id(%u) Error: no filename in shm buffer\n", (int) mypid, s->id);
         return;
     }

