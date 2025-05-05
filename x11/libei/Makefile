# $NetBSD: Makefile,v 1.1 2025/05/05 08:05:10 tnn Exp $

DISTNAME=		libei-1.4.0
CATEGORIES=		x11 devel
MASTER_SITES=		https://gitlab.freedesktop.org/libinput/libei/-/archive/${PKGVERSION_NOREV}/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://xorg.freedesktop.org/
COMMENT=		Library for Emulated Input
LICENSE=		mit

BUILD_DEPENDS+=		${PYPKGPREFIX}-jinja2-[0-9]*:../../textproc/py-jinja2
USE_LIBTOOL=		YES
USE_TOOLS+=		pkg-config

NOT_FOR_PLATFORM+=	Darwin-*-*

.include "../../mk/bsd.prefs.mk"
.include "../../devel/meson/build.mk"

# Disable Linux-only stuff for now. Needs libevdev and/or libsystemd.
MESON_ARGS+=		-Dliboeffis=disabled
MESON_ARGS+=		-Dlibeis=disabled
MESON_ARGS+=		-Dtests=disabled

.if defined(OPSYS_HAS_KQUEUE)
CFLAGS+=	-I${BUILDLINK_PREFIX.libepoll-shim}/include/libepoll-shim
.include "../../devel/libepoll-shim/buildlink3.mk"
.endif
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
