# $NetBSD: Makefile,v 1.13 2026/04/22 18:00:46 vins Exp $

DISTNAME=	worker-5.4.0
CATEGORIES=	x11 sysutils
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=workerfm/}
EXTRACT_SUFX=	.tar.zst

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	http://www.boomerangsworld.de/cms/worker/
COMMENT=	Orthodox file manager for the X Window System
LICENSE=	gnu-gpl-v2

EXTRACT_USING=		bsdtar

USE_LANGUAGES=		c c++
USE_CXX_FEATURES=	c++20 # designated initializers

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config bash:run zstd

PKGCONFIG_OVERRIDE+=	pkgconfig/worker.pc.in

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--without-hal	# obsolete and unsupported on pkgsrc

REPLACE_BASH+=		scripts/*.sh scripts/*r
REPLACE_PYTHON+=	scripts/*.py

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../lang/python/application.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
