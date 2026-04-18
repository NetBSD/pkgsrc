# $NetBSD: Makefile,v 1.2 2026/04/18 09:31:41 kikadf Exp $

DISTNAME=	labwc-0.9.7
CATEGORIES=	wayland
MASTER_SITES=	${MASTER_SITE_GITHUB:=labwc/}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://labwc.github.io/
COMMENT=	Wlroots-based compositor for Wayland, inspired by Openbox
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_MESSAGE.path=	Fixing pathes
SUBST_FILES.path+=	startlabwc.sh
SUBST_VARS.path+=	PREFIX PKG_SYSCONFBASE

EGDIR=			${PREFIX}/share/examples/labwc
PKG_SYSCONFSUBDIR=	xdg/labwc
INSTALL_MAKE_FLAGS+=	rcdir=${EGDIR}

# Fix: [../src/main.c:94] no fonts are available
DEPENDS+=	nerd-fonts-Hack-[0-9]*:../../fonts/nerd-fonts-Hack

CFLAGS+=	-I${BUILDLINK_PREFIX.libepoll-shim}/include/libepoll-shim

post-extract:
	${CP} ${FILESDIR}/startlabwc.sh.in ${WRKSRC}/startlabwc.sh

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/startlabwc.sh \
                ${DESTDIR}${PREFIX}/bin/startlabwc

.include "options.mk"

.include "../../devel/meson/build.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libepoll-shim/buildlink3.mk"
.include "../../devel/libsfdo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/seatd/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../wayland/wlroots/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
