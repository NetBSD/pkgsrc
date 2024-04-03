# $NetBSD: Makefile,v 1.3 2024/04/03 00:55:28 ktnb Exp $

DISTNAME=	xmenu-4.6.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=phillbush/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	ktnb@NetBSD.org
HOMEPAGE=	https://github.com/phillbush/xmenu/
COMMENT=	Menu utility for X11
LICENSE=	mit

WRKSRC=		${WRKDIR}/${DISTNAME}
MAKE_FLAGS+=	MANPREFIX=${PREFIX}/${PKGMANDIR}
EGDIR=		${PREFIX}/share/examples/xmenu

INSTALLATION_DIRS+=	${EGDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/xmenu.sh ${DESTDIR}${EGDIR}

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
