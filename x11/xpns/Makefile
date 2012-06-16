# $NetBSD: Makefile,v 1.27 2012/06/16 04:00:53 dholland Exp $

DISTNAME=	pns_source
PKGNAME=	xpns-1.0
PKGREVISION=	4
CATEGORIES=	x11 cad
MASTER_SITES=	http://robotics.ee.uwa.edu.au/pns/ftp/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	pgiffuni@fps.biblos.unal.edu.co
HOMEPAGE=	http://robotics.ee.uwa.edu.au/pns/
COMMENT=	Petri-Net Simulator for Xwindows

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}
MAKE_FILE=	makefile
BUILD_TARGET=	pns

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	xpns
SUBST_SED.paths=	-e 's,@PREFIX@,${PREFIX},'

INSTALLATION_DIRS=	bin lib/xpns share/doc/xpns

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pns ${DESTDIR}${PREFIX}/lib/xpns/
	${INSTALL_DATA} ${WRKSRC}/pns.hlp ${DESTDIR}${PREFIX}/lib/xpns/
	${INSTALL_DATA} ${WRKSRC}/pns.shell ${DESTDIR}${PREFIX}/lib/xpns/
	${INSTALL_SCRIPT} ${WRKSRC}/xpns ${DESTDIR}${PREFIX}/bin/xpns
	${INSTALL_DATA} ${WRKSRC}/*.net ${DESTDIR}${PREFIX}/share/doc/xpns/

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
