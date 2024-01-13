# $NetBSD: Makefile,v 1.2 2024/01/13 13:58:30 gdt Exp $

DISTNAME=	xmenu-4.6.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=phillbush/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kevin.bloom@posteo.net
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
