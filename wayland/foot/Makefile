# $NetBSD: Makefile,v 1.1 2026/04/14 12:11:48 kikadf Exp $

DISTNAME=	foot-1.25.0
CATEGORIES=	wayland
MASTER_SITES=	https://codeberg.org/dnkl/foot/releases/download/${PKGVERSION_NOREV}/

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://codeberg.org/dnkl/foot/
COMMENT=	Terminal for Wayland
LICENSE=	mit

USE_TOOLS+=	pkg-config

MESON_ARGS+=	-Dtests=false
MESON_ARGS+=	-Dterminfo=disabled

EGDIR=		${PREFIX}/share/examples/foot
OWN_DIRS+=	${PKG_SYSCONFDIR}/xdg/foot
CONF_FILES=	${EGDIR}/foot.ini ${PKG_SYSCONFDIR}/xdg/foot/foot.ini

.include "../../devel/meson/build.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../converters/utf8proc/buildlink3.mk"
CFLAGS+=	-I${BUILDLINK_PREFIX.libepoll-shim}/include/libepoll-shim
.include "../../devel/libepoll-shim/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
#.include "../../lang/python/application.mk"
.include "../../fonts/fcft/buildlink3.mk"
.include "../../devel/tllist/buildlink3.mk"
.include "../../devel/input-headers/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
