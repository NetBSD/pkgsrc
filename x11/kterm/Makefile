# $NetBSD: Makefile,v 1.8 2000/10/15 14:15:32 itojun Exp $

DISTNAME=	kterm-6.2.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

# the following patch includes NFS xauth patch, and kamo's wd0.2 patch.
PATCH_SITES+=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES+=	kterm-620-0213-20001010.diff.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	sakamoto@netbsd.org

USE_IMAKE=	YES
USE_XAW=	YES

BUILD_DEFS+=	KTERM_USE_WALLPAPER

.include "../../mk/bsd.prefs.mk"

XAW_TYPE?=	standard

.if defined(KTERM_USE_WALLPAPER) && ${KTERM_USE_WALLPAPER} == YES
USE_XPM=	YES
PATCH_SITES+=	http://delegate.uec.ac.jp:8081/club/mma/%7Etakkun/fun/handling/
PATCHFILES+=	KTerm-BGP-1.0.patch.gz
.endif

post-patch:
.if ${XAW_TYPE} != "standard"
	@${ECHO_MSG}  "===>  Applying Xaw scrollbar patch"
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-xaw3d
.endif

.include "../../mk/bsd.pkg.mk"
