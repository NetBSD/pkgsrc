# $NetBSD: Makefile,v 1.7 2023/10/23 06:37:58 wiz Exp $

DISTNAME=	xcb-util-errors-1.0.1
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	https://xcb.freedesktop.org/dist/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://xcb.freedesktop.org/
COMMENT=	Library for helping debug xcb problems
LICENSE=	x11

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config m4
USE_LIBTOOL=	yes

PKGCONFIG_OVERRIDE=	xcb-errors.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${USE_CROSS_COMPILE:tl} == "yes"
# XXX Why is this necessary here and not in other packages?
ALL_ENV+=	PKG_CONFIG_SYSROOT_DIR=${_CROSS_DESTDIR:Q}

# xcb-proto abuses pc_sysrootdir in its .pc files, causing the
# cross-destdir to be prefixed twice to paths.
ALL_ENV+=	PKG_CONFIG_FDO_SYSROOT_RULES=1
.endif

.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/tool.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
