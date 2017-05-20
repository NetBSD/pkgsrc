# $NetBSD: Makefile,v 1.19 2017/05/20 11:50:09 joerg Exp $

DISTNAME=		9wm-1.4.0
PKGREVISION=		1
CATEGORIES=		plan9 wm
MASTER_SITES=		${MASTER_SITE_GITHUB:=9wm/}
GITHUB_PROJECT=		9wm
GITHUB_TAG=		1.4.0

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/9wm/9wm
COMMENT=		Rio-like Window Manager for X
LICENSE=		mit

USE_TOOLS=		gmake

INSTALLATION_DIRS=      bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/9wm ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/9wm.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/9wm.1

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
