$NetBSD: patch-kioslave_nfs_rpc__nfs2__prot__xdr.c,v 1.1 2016/01/10 19:05:27 markd Exp $

*_U_LONG are obsolete and unavailable in 64-bit mode, use *_U_INT32 instead.

--- kioslave/nfs/rpc_nfs2_prot_xdr.c.orig	2015-11-05 04:25:02.000000000 +0000
+++ kioslave/nfs/rpc_nfs2_prot_xdr.c
@@ -115,16 +115,16 @@ xdr_fattr (XDR *xdrs, fattr *objp)
 				 return FALSE;
 
 		} else {
-		IXDR_PUT_U_LONG(buf, objp->mode);
-		IXDR_PUT_U_LONG(buf, objp->nlink);
-		IXDR_PUT_U_LONG(buf, objp->uid);
-		IXDR_PUT_U_LONG(buf, objp->gid);
-		IXDR_PUT_U_LONG(buf, objp->size);
-		IXDR_PUT_U_LONG(buf, objp->blocksize);
-		IXDR_PUT_U_LONG(buf, objp->rdev);
-		IXDR_PUT_U_LONG(buf, objp->blocks);
-		IXDR_PUT_U_LONG(buf, objp->fsid);
-		IXDR_PUT_U_LONG(buf, objp->fileid);
+		IXDR_PUT_U_INT32(buf, objp->mode);
+		IXDR_PUT_U_INT32(buf, objp->nlink);
+		IXDR_PUT_U_INT32(buf, objp->uid);
+		IXDR_PUT_U_INT32(buf, objp->gid);
+		IXDR_PUT_U_INT32(buf, objp->size);
+		IXDR_PUT_U_INT32(buf, objp->blocksize);
+		IXDR_PUT_U_INT32(buf, objp->rdev);
+		IXDR_PUT_U_INT32(buf, objp->blocks);
+		IXDR_PUT_U_INT32(buf, objp->fsid);
+		IXDR_PUT_U_INT32(buf, objp->fileid);
 		}
 		 if (!xdr_nfstime (xdrs, &objp->atime))
 			 return FALSE;
@@ -160,16 +160,16 @@ xdr_fattr (XDR *xdrs, fattr *objp)
 				 return FALSE;
 
 		} else {
-		objp->mode = IXDR_GET_U_LONG(buf);
-		objp->nlink = IXDR_GET_U_LONG(buf);
-		objp->uid = IXDR_GET_U_LONG(buf);
-		objp->gid = IXDR_GET_U_LONG(buf);
-		objp->size = IXDR_GET_U_LONG(buf);
-		objp->blocksize = IXDR_GET_U_LONG(buf);
-		objp->rdev = IXDR_GET_U_LONG(buf);
-		objp->blocks = IXDR_GET_U_LONG(buf);
-		objp->fsid = IXDR_GET_U_LONG(buf);
-		objp->fileid = IXDR_GET_U_LONG(buf);
+		objp->mode = IXDR_GET_U_INT32(buf);
+		objp->nlink = IXDR_GET_U_INT32(buf);
+		objp->uid = IXDR_GET_U_INT32(buf);
+		objp->gid = IXDR_GET_U_INT32(buf);
+		objp->size = IXDR_GET_U_INT32(buf);
+		objp->blocksize = IXDR_GET_U_INT32(buf);
+		objp->rdev = IXDR_GET_U_INT32(buf);
+		objp->blocks = IXDR_GET_U_INT32(buf);
+		objp->fsid = IXDR_GET_U_INT32(buf);
+		objp->fileid = IXDR_GET_U_INT32(buf);
 		}
 		 if (!xdr_nfstime (xdrs, &objp->atime))
 			 return FALSE;
@@ -230,10 +230,10 @@ xdr_sattr (XDR *xdrs, sattr *objp)
 				 return FALSE;
 
 		} else {
-		IXDR_PUT_U_LONG(buf, objp->mode);
-		IXDR_PUT_U_LONG(buf, objp->uid);
-		IXDR_PUT_U_LONG(buf, objp->gid);
-		IXDR_PUT_U_LONG(buf, objp->size);
+		IXDR_PUT_U_INT32(buf, objp->mode);
+		IXDR_PUT_U_INT32(buf, objp->uid);
+		IXDR_PUT_U_INT32(buf, objp->gid);
+		IXDR_PUT_U_INT32(buf, objp->size);
 		}
 		 if (!xdr_nfstime (xdrs, &objp->atime))
 			 return FALSE;
@@ -253,10 +253,10 @@ xdr_sattr (XDR *xdrs, sattr *objp)
 				 return FALSE;
 
 		} else {
-		objp->mode = IXDR_GET_U_LONG(buf);
-		objp->uid = IXDR_GET_U_LONG(buf);
-		objp->gid = IXDR_GET_U_LONG(buf);
-		objp->size = IXDR_GET_U_LONG(buf);
+		objp->mode = IXDR_GET_U_INT32(buf);
+		objp->uid = IXDR_GET_U_INT32(buf);
+		objp->gid = IXDR_GET_U_INT32(buf);
+		objp->size = IXDR_GET_U_INT32(buf);
 		}
 		 if (!xdr_nfstime (xdrs, &objp->atime))
 			 return FALSE;
@@ -455,9 +455,9 @@ xdr_writeargs (XDR *xdrs, writeargs *obj
 				 return FALSE;
 
 		} else {
-		IXDR_PUT_U_LONG(buf, objp->beginoffset);
-		IXDR_PUT_U_LONG(buf, objp->offset);
-		IXDR_PUT_U_LONG(buf, objp->totalcount);
+		IXDR_PUT_U_INT32(buf, objp->beginoffset);
+		IXDR_PUT_U_INT32(buf, objp->offset);
+		IXDR_PUT_U_INT32(buf, objp->totalcount);
 		}
 		 if (!xdr_bytes (xdrs, (char **)&objp->data.data_val, (u_int *) &objp->data.data_len, NFS_MAXDATA))
 			 return FALSE;
@@ -475,9 +475,9 @@ xdr_writeargs (XDR *xdrs, writeargs *obj
 				 return FALSE;
 
 		} else {
-		objp->beginoffset = IXDR_GET_U_LONG(buf);
-		objp->offset = IXDR_GET_U_LONG(buf);
-		objp->totalcount = IXDR_GET_U_LONG(buf);
+		objp->beginoffset = IXDR_GET_U_INT32(buf);
+		objp->offset = IXDR_GET_U_INT32(buf);
+		objp->totalcount = IXDR_GET_U_INT32(buf);
 		}
 		 if (!xdr_bytes (xdrs, (char **)&objp->data.data_val, (u_int *) &objp->data.data_len, NFS_MAXDATA))
 			 return FALSE;
@@ -637,11 +637,11 @@ xdr_statfsokres (XDR *xdrs, statfsokres 
 			 if (!xdr_u_int (xdrs, &objp->bavail))
 				 return FALSE;
 		} else {
-			IXDR_PUT_U_LONG(buf, objp->tsize);
-			IXDR_PUT_U_LONG(buf, objp->bsize);
-			IXDR_PUT_U_LONG(buf, objp->blocks);
-			IXDR_PUT_U_LONG(buf, objp->bfree);
-			IXDR_PUT_U_LONG(buf, objp->bavail);
+			IXDR_PUT_U_INT32(buf, objp->tsize);
+			IXDR_PUT_U_INT32(buf, objp->bsize);
+			IXDR_PUT_U_INT32(buf, objp->blocks);
+			IXDR_PUT_U_INT32(buf, objp->bfree);
+			IXDR_PUT_U_INT32(buf, objp->bavail);
 		}
 		return TRUE;
 	} else if (xdrs->x_op == XDR_DECODE) {
@@ -658,11 +658,11 @@ xdr_statfsokres (XDR *xdrs, statfsokres 
 			 if (!xdr_u_int (xdrs, &objp->bavail))
 				 return FALSE;
 		} else {
-			objp->tsize = IXDR_GET_U_LONG(buf);
-			objp->bsize = IXDR_GET_U_LONG(buf);
-			objp->blocks = IXDR_GET_U_LONG(buf);
-			objp->bfree = IXDR_GET_U_LONG(buf);
-			objp->bavail = IXDR_GET_U_LONG(buf);
+			objp->tsize = IXDR_GET_U_INT32(buf);
+			objp->bsize = IXDR_GET_U_INT32(buf);
+			objp->blocks = IXDR_GET_U_INT32(buf);
+			objp->bfree = IXDR_GET_U_INT32(buf);
+			objp->bavail = IXDR_GET_U_INT32(buf);
 		}
 	 return TRUE;
 	}
@@ -840,7 +840,7 @@ xdr_ppathcnf (XDR *xdrs, ppathcnf *objp)
 				 return FALSE;
 
 		} else {
-		IXDR_PUT_LONG(buf, objp->pc_link_max);
+		IXDR_PUT_INT32(buf, objp->pc_link_max);
 		IXDR_PUT_SHORT(buf, objp->pc_max_canon);
 		IXDR_PUT_SHORT(buf, objp->pc_max_input);
 		IXDR_PUT_SHORT(buf, objp->pc_name_max);
@@ -884,7 +884,7 @@ xdr_ppathcnf (XDR *xdrs, ppathcnf *objp)
 				 return FALSE;
 
 		} else {
-		objp->pc_link_max = IXDR_GET_LONG(buf);
+		objp->pc_link_max = IXDR_GET_INT32(buf);
 		objp->pc_max_canon = IXDR_GET_SHORT(buf);
 		objp->pc_max_input = IXDR_GET_SHORT(buf);
 		objp->pc_name_max = IXDR_GET_SHORT(buf);
