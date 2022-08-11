# $NetBSD: Makefile,v 1.50 2022/08/11 05:05:52 gutteridge Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	1.9.11
DISTNAME=	xfce4-screenshooter-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/apps/xfce4-screenshooter/${VERSION:R}/

HOMEPAGE=	https://archive.xfce.org/src/apps/xfce4-screenshooter/${VERSION:R}/
COMMENT=	Xfce screenshoot application

BUILDLINK_API_DEPENDS.xfce4-panel+=	xfce4-panel>=4.14.0
.include "../../x11/xfce4-panel/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxfce4ui+=	libxfce4ui>=4.14.0
.include "../../x11/libxfce4ui/buildlink3.mk"
BUILDLINK_API_DEPENDS.libxfce4util+=	libxfce4util>=4.14.0
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
