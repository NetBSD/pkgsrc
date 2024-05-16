# $NetBSD: Makefile,v 1.43 2024/05/16 06:15:44 wiz Exp $

DISTNAME=	elementary-1.7.10
PKGREVISION=	13
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
USE_TOOLS+=	autoconf automake # because I patched configure.ac
USE_TOOLS+=	gmake
# override for hardcoded aclocal-1.13 in configure script
CONFIGURE_ENV+=	ACLOCAL='aclocal'
# override for hardcoded automake-1.13 in Makefiles
MAKE_FLAGS+=	AUTOMAKE="automake -af"

PKGCONFIG_OVERRIDE=	elementary

# currently it is like it is
MODULE_ARCH=		${LOWER_OPSYS}-${MACHINE_ARCH}-1.7.10
PLIST_SUBST=		MODULE_ARCH=${MODULE_ARCH}
PRINT_PLIST_AWK+=	{ gsub(/${MODULE_ARCH}/, "$${MODULE_ARCH}") }

MAKE_FLAGS+=	MODULE_ARCH=${MODULE_ARCH}

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
