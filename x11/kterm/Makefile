# $NetBSD: Makefile,v 1.16 2001/12/02 21:29:21 wiz Exp $

DISTNAME=	kterm-6.2.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

# the following patch includes NFS xauth patch, and kamo's wd0.2 patch.
PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES+=	kterm-620-0213-20010706.diff.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	sakamoto@netbsd.org
COMMENT=	Multi-lingual terminal emulator for X

USE_IMAKE=	YES

BUILD_DEFS+=	KTERM_USE_WALLPAPER

.include "../../mk/bsd.prefs.mk"

.if defined(KTERM_USE_WALLPAPER)
.if ${KTERM_USE_WALLPAPER} == "imlib"
PATCH_SITES_KTerm-BGP-Imlib-1.0.patch.gz=	http://delegate.uec.ac.jp:8081/club/mma/%7Etakkun/fun/handling/
PATCHFILES+=	KTerm-BGP-Imlib-1.0.patch.gz
BUILDLINK_DEPENDS.imlib?=	imlib>=1.9.4
USE_CONFIG_WRAPPER=		YES
.include "../../graphics/imlib/buildlink.mk"
.elif ${KTERM_USE_WALLPAPER} == "YES"
PATCH_SITES_KTerm-BGP-1.0.patch.gz=	http://delegate.uec.ac.jp:8081/club/mma/%7Etakkun/fun/handling/
PATCHFILES+=	KTerm-BGP-1.0.patch.gz
.include "../../graphics/xpm/buildlink.mk"
.endif
.endif

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm")
post-patch:
	@${ECHO_MSG}  "===>  Applying Xaw scrollbar patch"
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-xaw3d
.endif

.include "../../mk/xaw.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
