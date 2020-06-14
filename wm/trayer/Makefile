# $NetBSD: Makefile,v 1.15 2020/06/14 16:20:15 nia Exp $

DISTNAME=	trayer-1.1.8
CATEGORIES=	wm x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=sargon/}
GITHUB_PROJECT=	trayer-srg
GITHUB_TAG=	${PKGNAME_NOREV}

MAINTAINER=	cheusov@NetBSD.org
HOMEPAGE=	https://github.com/sargon/trayer-srg
COMMENT=	Lightweight GTK2-based systray for UNIX desktop
LICENSE=	mit

USE_TOOLS+=	gmake pkg-config bash

HAS_CONFIGURE=	yes

MAKE_FLAGS=	CFLAGS=${CFLAGS:Q}

AUTO_MKDIRS=	yes

CONFIG_SHELL=	bash

CONFIGURE_ARGS+=	--prefix=${PREFIX}

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/trayer/

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2-xlib/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
