# $NetBSD: Makefile,v 1.9 2025/06/06 16:34:18 vins Exp $

DISTNAME=	worker-5.2.1
CATEGORIES=	x11 sysutils
MASTER_SITES=	http://www.boomerangsworld.de/cms/worker/downloads/
EXTRACT_SUFX=	.tar.zst

MAINTAINER=	dvollen@gmail.com
HOMEPAGE=	http://www.boomerangsworld.de/cms/worker/downloads/
COMMENT=	Orthodox file manager for the X Window System
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++20 # designated initializers

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config bash:run

PKGCONFIG_OVERRIDE+=	pkgconfig/worker.pc.in

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--without-avfs
CONFIGURE_ARGS+=	--without-hal

REPLACE_BASH+=		scripts/*.sh scripts/*r
REPLACE_PYTHON+=	scripts/*.py

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../lang/python/application.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
