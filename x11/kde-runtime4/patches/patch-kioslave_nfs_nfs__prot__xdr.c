$NetBSD: patch-kioslave_nfs_nfs__prot__xdr.c,v 1.1 2013/06/03 10:23:33 jperkin Exp $

*_U_LONG are obsolete and unavailable in 64-bit mode, use *_U_INT32 instead.

--- kioslave/nfs/nfs_prot_xdr.c.orig	2013-05-03 04:36:36.766201695 +0000
+++ kioslave/nfs/nfs_prot_xdr.c
@@ -141,16 +141,16 @@ xdr_fattr(XDR *xdrs, fattr *objp)
 
 	  }
 	  else {
-		 IXDR_PUT_U_LONG(buf,objp->mode);
-		 IXDR_PUT_U_LONG(buf,objp->nlink);
-		 IXDR_PUT_U_LONG(buf,objp->uid);
-		 IXDR_PUT_U_LONG(buf,objp->gid);
-		 IXDR_PUT_U_LONG(buf,objp->size);
-		 IXDR_PUT_U_LONG(buf,objp->blocksize);
-		 IXDR_PUT_U_LONG(buf,objp->rdev);
-		 IXDR_PUT_U_LONG(buf,objp->blocks);
-		 IXDR_PUT_U_LONG(buf,objp->fsid);
-		 IXDR_PUT_U_LONG(buf,objp->fileid);
+		 IXDR_PUT_U_INT32(buf,objp->mode);
+		 IXDR_PUT_U_INT32(buf,objp->nlink);
+		 IXDR_PUT_U_INT32(buf,objp->uid);
+		 IXDR_PUT_U_INT32(buf,objp->gid);
+		 IXDR_PUT_U_INT32(buf,objp->size);
+		 IXDR_PUT_U_INT32(buf,objp->blocksize);
+		 IXDR_PUT_U_INT32(buf,objp->rdev);
+		 IXDR_PUT_U_INT32(buf,objp->blocks);
+		 IXDR_PUT_U_INT32(buf,objp->fsid);
+		 IXDR_PUT_U_INT32(buf,objp->fileid);
 	  }
 	 if (!xdr_nfstime(xdrs, &objp->atime)) {
 		 return (FALSE);
@@ -202,16 +202,16 @@ xdr_fattr(XDR *xdrs, fattr *objp)
 
 	  }
 	  else {
-		 objp->mode = IXDR_GET_U_LONG(buf);
-		 objp->nlink = IXDR_GET_U_LONG(buf);
-		 objp->uid = IXDR_GET_U_LONG(buf);
-		 objp->gid = IXDR_GET_U_LONG(buf);
-		 objp->size = IXDR_GET_U_LONG(buf);
-		 objp->blocksize = IXDR_GET_U_LONG(buf);
-		 objp->rdev = IXDR_GET_U_LONG(buf);
-		 objp->blocks = IXDR_GET_U_LONG(buf);
-		 objp->fsid = IXDR_GET_U_LONG(buf);
-		 objp->fileid = IXDR_GET_U_LONG(buf);
+		 objp->mode = IXDR_GET_U_INT32(buf);
+		 objp->nlink = IXDR_GET_U_INT32(buf);
+		 objp->uid = IXDR_GET_U_INT32(buf);
+		 objp->gid = IXDR_GET_U_INT32(buf);
+		 objp->size = IXDR_GET_U_INT32(buf);
+		 objp->blocksize = IXDR_GET_U_INT32(buf);
+		 objp->rdev = IXDR_GET_U_INT32(buf);
+		 objp->blocks = IXDR_GET_U_INT32(buf);
+		 objp->fsid = IXDR_GET_U_INT32(buf);
+		 objp->fileid = IXDR_GET_U_INT32(buf);
 	  }
 	 if (!xdr_nfstime(xdrs, &objp->atime)) {
 		 return (FALSE);
@@ -295,10 +295,10 @@ xdr_sattr(XDR *xdrs, sattr *objp)
 
 	  }
 	  else {
-		 IXDR_PUT_U_LONG(buf,objp->mode);
-		 IXDR_PUT_U_LONG(buf,objp->uid);
-		 IXDR_PUT_U_LONG(buf,objp->gid);
-		 IXDR_PUT_U_LONG(buf,objp->size);
+		 IXDR_PUT_U_INT32(buf,objp->mode);
+		 IXDR_PUT_U_INT32(buf,objp->uid);
+		 IXDR_PUT_U_INT32(buf,objp->gid);
+		 IXDR_PUT_U_INT32(buf,objp->size);
 	  }
 	 if (!xdr_nfstime(xdrs, &objp->atime)) {
 		 return (FALSE);
@@ -326,10 +326,10 @@ xdr_sattr(XDR *xdrs, sattr *objp)
 
 	  }
 	  else {
-		 objp->mode = IXDR_GET_U_LONG(buf);
-		 objp->uid = IXDR_GET_U_LONG(buf);
-		 objp->gid = IXDR_GET_U_LONG(buf);
-		 objp->size = IXDR_GET_U_LONG(buf);
+		 objp->mode = IXDR_GET_U_INT32(buf);
+		 objp->uid = IXDR_GET_U_INT32(buf);
+		 objp->gid = IXDR_GET_U_INT32(buf);
+		 objp->size = IXDR_GET_U_INT32(buf);
 	  }
 	 if (!xdr_nfstime(xdrs, &objp->atime)) {
 		 return (FALSE);
@@ -575,9 +575,9 @@ xdr_writeargs(XDR *xdrs, writeargs *objp
 
 	  }
 	  else {
-		 IXDR_PUT_U_LONG(buf,objp->beginoffset);
-		 IXDR_PUT_U_LONG(buf,objp->offset);
-		 IXDR_PUT_U_LONG(buf,objp->totalcount);
+		 IXDR_PUT_U_INT32(buf,objp->beginoffset);
+		 IXDR_PUT_U_INT32(buf,objp->offset);
+		 IXDR_PUT_U_INT32(buf,objp->totalcount);
 	  }
 	 if (!xdr_bytes(xdrs, (char **)&objp->data.data_val, (u_int *)&objp->data.data_len, NFS_MAXDATA)) {
 		 return (FALSE);
@@ -602,9 +602,9 @@ xdr_writeargs(XDR *xdrs, writeargs *objp
 
 	  }
 	  else {
-		 objp->beginoffset = IXDR_GET_U_LONG(buf);
-		 objp->offset = IXDR_GET_U_LONG(buf);
-		 objp->totalcount = IXDR_GET_U_LONG(buf);
+		 objp->beginoffset = IXDR_GET_U_INT32(buf);
+		 objp->offset = IXDR_GET_U_INT32(buf);
+		 objp->totalcount = IXDR_GET_U_INT32(buf);
 	  }
 	 if (!xdr_bytes(xdrs, (char **)&objp->data.data_val, (u_int *)&objp->data.data_len, NFS_MAXDATA)) {
 		 return (FALSE);
@@ -808,11 +808,11 @@ xdr_statfsokres(XDR *xdrs, statfsokres *
 
 	  }
 	  else {
-		 IXDR_PUT_U_LONG(buf,objp->tsize);
-		 IXDR_PUT_U_LONG(buf,objp->bsize);
-		 IXDR_PUT_U_LONG(buf,objp->blocks);
-		 IXDR_PUT_U_LONG(buf,objp->bfree);
-		 IXDR_PUT_U_LONG(buf,objp->bavail);
+		 IXDR_PUT_U_INT32(buf,objp->tsize);
+		 IXDR_PUT_U_INT32(buf,objp->bsize);
+		 IXDR_PUT_U_INT32(buf,objp->blocks);
+		 IXDR_PUT_U_INT32(buf,objp->bfree);
+		 IXDR_PUT_U_INT32(buf,objp->bavail);
 	  }
 
  	 return (TRUE);
@@ -837,11 +837,11 @@ xdr_statfsokres(XDR *xdrs, statfsokres *
 
 	  }
 	  else {
-		 objp->tsize = IXDR_GET_U_LONG(buf);
-		 objp->bsize = IXDR_GET_U_LONG(buf);
-		 objp->blocks = IXDR_GET_U_LONG(buf);
-		 objp->bfree = IXDR_GET_U_LONG(buf);
-		 objp->bavail = IXDR_GET_U_LONG(buf);
+		 objp->tsize = IXDR_GET_U_INT32(buf);
+		 objp->bsize = IXDR_GET_U_INT32(buf);
+		 objp->blocks = IXDR_GET_U_INT32(buf);
+		 objp->bfree = IXDR_GET_U_INT32(buf);
+		 objp->bavail = IXDR_GET_U_INT32(buf);
 	  }
 	 return(TRUE);
 	}
