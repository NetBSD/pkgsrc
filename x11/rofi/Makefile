# $NetBSD: Makefile,v 1.3 2016/06/13 11:20:29 wiz Exp $

DISTNAME=	rofi-1.0.1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=DaveDavenport/}
# We need to specify this way to get submodules fetched
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://davedavenport.github.io/rofi/
COMMENT=	Window switcher, run dialog and dmenu replacement
LICENSE=	x11

USE_TOOLS+=	pkg-config bash

GNU_CONFIGURE=	yes

REPLACE_BASH+=	script/rofi-sensible-terminal

.include "../../x11/rofi/options.mk"

.include "../../x11/startup-notification/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../x11/xcb-util/buildlink3.mk"
.include "../../x11/xcb-util-wm/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
