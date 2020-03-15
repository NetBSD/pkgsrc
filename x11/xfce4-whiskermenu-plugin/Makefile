# $NetBSD: Makefile,v 1.31 2020/03/15 05:35:08 gutteridge Exp $

VERSION=	2.4.3
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

.include "../../x11/xfce4-garcon/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
