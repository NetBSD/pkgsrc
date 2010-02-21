# $NetBSD: Makefile,v 1.47 2010/02/21 15:39:12 wiz Exp $

DISTNAME=	kterm-6.2.0
PKGREVISION=	13
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

# the following patch includes NFS xauth patch, and kamo's wd0.2 patch.
PATCH_SITES=	ftp://ftp.kame.net/pub/kame/misc/
PATCHFILES=	kterm-620-0213-20030825.diff.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# none
COMMENT=	Multi-lingual terminal emulator for X

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	YES

SPECIAL_PERMS=	${PREFIX:Q}/bin/kterm ${SETUID_ROOT_PERMS}

BUILD_DEFS+=	KTERM_USE_WALLPAPER

.include "../../mk/bsd.prefs.mk"

.if defined(KTERM_USE_WALLPAPER)
.  if ${KTERM_USE_WALLPAPER} == "imlib"
SITES.KTerm-BGP-Imlib-1.0.patch.gz=	http://delegate.uec.ac.jp:8081/club/mma/%7Etakkun/fun/handling/
PATCHFILES+=	KTerm-BGP-Imlib-1.0.patch.gz
.    include "../../graphics/imlib/buildlink3.mk"
#.  elif ${KTERM_USE_WALLPAPER} == "YES"
#SITES.KTerm-BGP-1.0.patch.gz=	http://delegate.uec.ac.jp:8081/club/mma/%7Etakkun/fun/handling/
#PATCHFILES+=	KTerm-BGP-1.0.patch.gz
#.    include "../../x11/libXpm/buildlink3.mk"
.  endif
.endif

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm" || ${XAW_TYPE} == "neXtaw")
post-patch:
	@${ECHO_MSG}  "===>  Applying Xaw scrollbar patch"
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR:Q}/patch-xaw3d
.endif

.include "../../mk/xaw.buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
