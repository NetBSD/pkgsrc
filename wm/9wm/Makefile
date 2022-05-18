# $NetBSD: Makefile,v 1.22 2022/05/18 19:48:23 nikita Exp $

DISTNAME=		9wm-1.4.2
CATEGORIES=		plan9 wm
MASTER_SITES=		${MASTER_SITE_GITHUB:=9wm/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/9wm/9wm
COMMENT=		Rio-like Window Manager for X
LICENSE=		mit

USE_TOOLS=		gmake

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

BUILDLINK_TRANSFORM+=	rm:-pedantic

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/9wm ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/9wm.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/9wm.1

.include "../../x11/libXext/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
