# $NetBSD: Makefile,v 1.5 2023/07/03 11:29:04 vins Exp $

DISTNAME=	xidle-20220718
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	ftp://ftp.NetBSD.org/pub/NetBSD/misc/vins/dists/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://man.openbsd.org/xidle.1
COMMENT=	Run a program on X inactivity
LICENSE=	isc

MAKE_FLAGS+=	X11BASE=${X11BASE}
MAKE_FLAGS+=	MANDIR=${PKGMANDIR}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths+=	xidle.c
SUBST_FILES.paths+=	xidle.1
SUBST_VARS.paths=	PREFIX
SUBST_MESSAGE.paths=	Setting default locker's path.

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xidle ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/xidle.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"	# strtonum()
CFLAGS+=	-D_OPENBSD_SOURCE
.endif

.if ${OPSYS} == "Linux"		# strtonum()
.  include "../../devel/libbsd/buildlink3.mk"
.endif

.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
