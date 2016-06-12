# $NetBSD: Makefile,v 1.1 2016/06/12 20:31:10 kamil Exp $

DISTNAME=	rofi-1.0.1
CATEGORIES=	x11
# We need to specify this long path to get submodules fetched
MASTER_SITES=	${MASTER_SITE_GITHUB:=DaveDavenport/${PKGBASE}/releases/download/${PKGVERSION_NOREV}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://davedavenport.github.io/rofi/
COMMENT=	Window switcher, run dialog and dmenu replacement
LICENSE=	x11

USE_TOOLS+=	pkg-config bash

GNU_CONFIGURE=	yes

REPLACE_BASH+=	script/rofi-sensible-terminal

.include "../../wip/rofi/options.mk"

.include "../../x11/startup-notification/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
