# $NetBSD: Makefile,v 1.56 2026/11/17 12:08:34 wiz Exp $

DISTNAME=	elementary-1.7.10
PKGREVISION=	25
CATEGORIES=	x11
MASTER_SITES=	https://download.enlightenment.org/att/releases/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.enlightenment.org/
COMMENT=	E17 Widget Library
LICENSE=	gnu-lgpl-v2.1

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_TOOLS+=	autoconf automake
USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE=	elementary

# currently it is like it is
MODULE_ARCH=		${LOWER_OPSYS}-${MACHINE_ARCH}-1.7.10
PLIST_SUBST=		MODULE_ARCH=${MODULE_ARCH}
PRINT_PLIST_AWK+=	{ gsub(/${MODULE_ARCH}/, "$${MODULE_ARCH}") }

MAKE_FLAGS+=	MODULE_ARCH=${MODULE_ARCH}

pre-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} autoreconf -fiv

.include "../../devel/ecore/buildlink3.mk"
.include "../../graphics/edje/buildlink3.mk"
.include "../../sysutils/edbus/buildlink3.mk"
.include "../../sysutils/efreet/buildlink3.mk"
.include "../../devel/eet/buildlink3.mk"
.include "../../graphics/evas-png/buildlink3.mk"
.include "../../graphics/evas-jpeg/buildlink3.mk"
.include "../../graphics/evas/buildlink3.mk"
.include "../../devel/eio/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
#.include "../../devel/ewheather/buildlink3.mk"
#.include "../../devel/emap/buildlink3.mk"
#.include "../../devel/ethumb/buildlink3.mk"
#.include "../../devel/emotion/buildlink3.mk"
#.include "../../devel/webkit/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
