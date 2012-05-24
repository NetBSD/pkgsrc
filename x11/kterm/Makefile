# $NetBSD: Makefile,v 1.55 2012/05/24 19:54:44 ryoon Exp $

DISTNAME=	kterm-6.2.0
PKGREVISION=	21
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XCONTRIB:=applications/}

# the following patch includes NFS xauth patch, and kamo's wd0.2 patch.
PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCHFILES=	kterm-6.2.0-termios-wd0.2.patch2 \
		kterm-6.2.0-scroll-wd0.2.patch \
		kterm-6.2.0.NFS-xauth.patch \
		kterm-6.2.0.ext05.patch.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	# none
COMMENT=	Multi-lingual terminal emulator for X

PKG_DESTDIR_SUPPORT=	user-destdir

USE_IMAKE=	YES

SPECIAL_PERMS=	${PREFIX:Q}/bin/kterm ${SETUID_ROOT_PERMS}

.include "../../mk/bsd.prefs.mk"

.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm" || ${XAW_TYPE} == "neXtaw")
post-patch:
	@${ECHO_MSG}  "===>  Applying Xaw scrollbar patch"
	@${PATCH} ${PATCH_ARGS} < ${FILESDIR:Q}/patch-xaw3d
.endif

.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
