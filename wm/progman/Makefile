# $NetBSD: Makefile,v 1.1 2021/11/19 18:59:09 sjmulder Exp $

DISTNAME=	progman-1.0
CATEGORIES=	wm
MASTER_SITES=	${MASTER_SITE_GITHUB:=jcs/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	sjmulder@NetBSD.org
HOMEPAGE=	https://github.com/jcs/progman
COMMENT=	Window manager resembling Windows 3's Program Manager
LICENSE=	mit

USE_TOOLS+=	pkg-config

# Supplies xxd utility
TOOL_DEPENDS+=	vim-share-[0-9]*:../../editors/vim-share

CFLAGS+=	-DINFTIM=-1
LDFLAGS+=	-lXext

MAKE_FLAGS+=	PREFIX=${DESTDIR:Q}${PREFIX:Q}
MAKE_FLAGS+=	MANDIR=${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR}/man1

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
