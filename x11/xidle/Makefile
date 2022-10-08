# $NetBSD: Makefile,v 1.1 2022/10/08 10:06:51 bsiegert Exp $

DISTNAME=	xidle-20220718
CATEGORIES=	x11
MASTER_SITES=	https://sehnsucht.multics.org/pub/pkgsrc/distfiles/
DIST_SUBDIR=	${PKGNAME_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	vms@retrobsd.ddns.net
HOMEPAGE=	https://man.openbsd.org/xidle.1
COMMENT=	Run a program on X inactivity
LICENSE=	isc

MAKEFLAGS+=	X11BASE=${X11BASE}
MAKEFLAGS+=	MANDIR=${PKGMANDIR}
MAKEFLAGS+=	CFLAGS=${CFLAGS:Q}

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

.if ${OPSYS} == "Linux" 	# strtonum()
LDFLAGS+=   -lbsd
.include "../../devel/libbsd/buildlink3.mk"
.endif

.include "../../x11/libXdmcp/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/libXau/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
