# $NetBSD: Makefile,v 1.8 2012/07/30 02:59:21 dholland Exp $
#

DISTNAME=		xgrk-1.6.3
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		http://users.softlab.ece.ntua.gr/~sivann/software/xgrk/

MAINTAINER=		is@NetBSD.org
HOMEPAGE=		http://www.softlab.ece.ntua.gr/~sivann/software/xgrk/
COMMENT=		Greek keyboard switcher for X11

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake

INSTALLATION_DIRS=	bin share/doc/xgrk

do-install:
	${INSTALL_PROGRAM}	${WRKSRC}/xgrk	${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM}	${WRKSRC}/xgrk2	${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA}		${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/xgrk

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
