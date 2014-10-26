$NetBSD: patch-intel_intel__bufmgr__gem.c,v 1.5 2014/10/26 10:20:10 wiz Exp $

--- intel/intel_bufmgr_gem.c.orig	2014-09-28 16:19:54.000000000 +0000
+++ intel/intel_bufmgr_gem.c
@@ -47,6 +47,7 @@
 #include <unistd.h>
 #include <assert.h>
 #include <pthread.h>
+#include <stddef.h>
 #include <sys/ioctl.h>
 #include <sys/stat.h>
 #include <sys/types.h>
@@ -399,13 +400,13 @@ drm_intel_gem_dump_validation_list(drm_i
 			    (drm_intel_bo_gem *) target_bo;
 
 			DBG("%2d: %d (%s)@0x%08llx -> "
-			    "%d (%s)@0x%08lx + 0x%08x\n",
+			    "%d (%s)@0x%08llx + 0x%08x\n",
 			    i,
 			    bo_gem->gem_handle, bo_gem->name,
 			    (unsigned long long)bo_gem->relocs[j].offset,
 			    target_gem->gem_handle,
 			    target_gem->name,
-			    target_bo->offset64,
+			    (unsigned long long)target_bo->offset64,
 			    bo_gem->relocs[j].delta);
 		}
 	}
@@ -1380,12 +1381,10 @@ map_gtt(drm_intel_bo *bo)
 		}
 
 		/* and mmap it */
-		bo_gem->gtt_virtual = drm_mmap(0, bo->size, PROT_READ | PROT_WRITE,
-					       MAP_SHARED, bufmgr_gem->fd,
-					       mmap_arg.offset);
-		if (bo_gem->gtt_virtual == MAP_FAILED) {
+		ret = drmMap(bufmgr_gem->fd, mmap_arg.offset, bo->size,
+		    &bo_gem->gtt_virtual);
+		if (ret) {
 			bo_gem->gtt_virtual = NULL;
-			ret = -errno;
 			DBG("%s:%d: Error mapping buffer %d (%s): %s .\n",
 			    __FILE__, __LINE__,
 			    bo_gem->gem_handle, bo_gem->name,
@@ -1991,8 +1990,9 @@ drm_intel_update_buffer_offsets(drm_inte
 
 		/* Update the buffer offset */
 		if (bufmgr_gem->exec_objects[i].offset != bo->offset64) {
-			DBG("BO %d (%s) migrated: 0x%08lx -> 0x%08llx\n",
-			    bo_gem->gem_handle, bo_gem->name, bo->offset64,
+			DBG("BO %d (%s) migrated: 0x%08llx -> 0x%08llx\n",
+			    bo_gem->gem_handle, bo_gem->name,
+			    (unsigned long long)bo->offset64,
 			    (unsigned long long)bufmgr_gem->exec_objects[i].
 			    offset);
 			bo->offset64 = bufmgr_gem->exec_objects[i].offset;
@@ -2012,8 +2012,9 @@ drm_intel_update_buffer_offsets2 (drm_in
 
 		/* Update the buffer offset */
 		if (bufmgr_gem->exec2_objects[i].offset != bo->offset64) {
-			DBG("BO %d (%s) migrated: 0x%08lx -> 0x%08llx\n",
-			    bo_gem->gem_handle, bo_gem->name, bo->offset64,
+			DBG("BO %d (%s) migrated: 0x%08llx -> 0x%08llx\n",
+			    bo_gem->gem_handle, bo_gem->name,
+			    (unsigned long long)bo->offset64,
 			    (unsigned long long)bufmgr_gem->exec2_objects[i].offset);
 			bo->offset64 = bufmgr_gem->exec2_objects[i].offset;
 			bo->offset = bufmgr_gem->exec2_objects[i].offset;
