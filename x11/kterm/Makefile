# $NetBSD: Makefile,v 1.30 2004/04/24 22:25:24 snj Exp $

DISTNAME=	kterm-6.2.0
PKGREVISION=	7
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

# the following patch includes NFS xauth patch, and kamo's wd0.2 patch.
PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	kterm-620-0213-20030825.diff.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	sakamoto@NetBSD.org
HOMEPAGE=	# none
COMMENT=	Multi-lingual terminal emulator for X

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
USE_IMAKE=	YES

_SETUID_ROOT=	${ROOT_USER} ${ROOT_GROUP} 4711
SPECIAL_PERMS=	${PREFIX}/bin/kterm ${_SETUID_ROOT}

BUILD_DEFS+=	KTERM_USE_WALLPAPER

.include "../../mk/bsd.prefs.mk"

.if defined(KTERM_USE_WALLPAPER)
.  if ${KTERM_USE_WALLPAPER} == "imlib"
SITES_KTerm-BGP-Imlib-1.0.patch.gz=	http://delegate.uec.ac.jp:8081/club/mma/%7Etakkun/fun/handling/
PATCHFILES+=	KTerm-BGP-Imlib-1.0.patch.gz
.    include "../../graphics/imlib/buildlink3.mk"
.  elif ${KTERM_USE_WALLPAPER} == "YES"
SITES_KTerm-BGP-1.0.patch.gz=	http://delegate.uec.ac.jp:8081/club/mma/%7Etakkun/fun/handling/
PATCHFILES+=	KTerm-BGP-1.0.patch.gz
.    include "../../graphics/xpm/buildlink3.mk"
.  endif
.endif

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm" || ${XAW_TYPE} == "neXtaw")
post-patch:
	@${ECHO_MSG}  "===>  Applying Xaw scrollbar patch"
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR}/patch-xaw3d
.endif

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
