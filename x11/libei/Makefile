# $NetBSD: Makefile,v 1.3 2026/04/13 16:52:39 tnn Exp $

DISTNAME=		libei-1.4.1
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

CFLAGS.SunOS+=		-D_XOPEN_SOURCE=600	# CMSG_SPACE
CFLAGS.SunOS+=		-D__EXTENSIONS__=1	# strndup
LDFLAGS.SunOS+=		-lsocket

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
