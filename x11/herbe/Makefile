# $NetBSD: Makefile,v 1.2 2023/11/12 13:24:08 wiz Exp $

# herbe does not contain a man page see below for info
# https://github.com/dudik/herbe/blob/1.0.0/README.md

DISTNAME=	herbe-1.0.0
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=dudik/}

MAINTAINER=	kevin.bloom@posteo.net
HOMEPAGE=	https://github.com/dudik/herbe/
COMMENT=	Daemon-less notifications without D-Bus
LICENSE=	mit

MAKE_FLAGS+=	CC=${CC:Q}
MAKE_FLAGS+=	PREFIX=${PREFIX}

DOC_DIR=	${PREFIX}/share/doc/herbe

INSTALLATION_DIRS+=	${DOC_DIR}

post-install:
	${INSTALL_MAN} ${WRKSRC}/README.md ${DESTDIR}${DOC_DIR}

.include "../../mk/pthread.buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
