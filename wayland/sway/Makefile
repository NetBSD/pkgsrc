# $NetBSD: Makefile,v 1.1 2026/04/14 11:32:14 kikadf Exp $

DISTNAME=	sway-1.11
CATEGORIES=	wayland
MASTER_SITES=	${MASTER_SITE_GITHUB:=swaywm/}

MAINTAINER=	dan@alt.md
HOMEPAGE=	https://swaywm.org/
COMMENT=	Tilling, i3-compatible Wayland compositor
LICENSE=	mit

USE_TOOLS+=	pkg-config

EGDIR=		${PREFIX}/share/examples/sway
OWN_DIRS+=	${PKG_SYSCONFDIR}/sway
CONF_FILES=	${EGDIR}/config ${PKG_SYSCONFDIR}/sway/config

post-install:
	${INSTALL_SCRIPT} ${FILESDIR}/startsway.sh \
		${DESTDIR}${PREFIX}/bin/startsway

.include "../../devel/meson/build.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../devel/basu/buildlink3.mk"
.include "../../devel/libevdev-chunk/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../sysutils/seatd/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../wayland/wlroots/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
