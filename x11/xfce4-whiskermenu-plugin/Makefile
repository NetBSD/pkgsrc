# $NetBSD: Makefile,v 1.48 2023/01/24 01:04:58 gutteridge Exp $

VERSION=	2.7.2
DISTNAME=	xfce4-whiskermenu-plugin-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/panel-plugins/xfce4-whiskermenu-plugin/${VERSION:R}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://gottcode.org/xfce4-whiskermenu-plugin/
COMMENT=	Alternate application launcher for Xfce
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config msgfmt perl intltool

BUILDLINK_TRANSFORM.SunOS+=     rm:-Wl,--as-needed
BUILDLINK_TRANSFORM.SunOS+=     rm:-Wl,-O1

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
