# $NetBSD: Makefile,v 1.48 2026/01/07 08:49:47 wiz Exp $

DISTNAME=	rofi-1.7.9.1
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=davatorium/}
# We need to specify this way to get submodules fetched
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/davatorium/rofi
COMMENT=	Window switcher, run dialog and dmenu replacement
LICENSE=	x11

USE_TOOLS+=	pkg-config bash:run flex bison

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	YACC='bison -y'

REPLACE_BASH+=	script/rofi-sensible-terminal
REPLACE_BASH+=	script/rofi-theme-selector

TEST_TARGET=	check

.include "../../devel/check/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../x11/xcb-util-cursor/buildlink3.mk"
.include "../../x11/xcb-util-keysyms/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../x11/xcb-util-xrm/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
