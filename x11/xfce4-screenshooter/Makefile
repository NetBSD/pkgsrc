# $NetBSD: Makefile,v 1.67 2024/05/29 16:35:16 adam Exp $

PKGREVISION= 3
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	1.10.5
DISTNAME=	xfce4-screenshooter-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/apps/xfce4-screenshooter/${VERSION:R}/

HOMEPAGE=	https://archive.xfce.org/src/apps/xfce4-screenshooter/${VERSION:R}/
COMMENT=	Xfce screenshot application

DEPENDS+=	zenity-[0-9]*:../../x11/zenity

.include "../../devel/xfce4-conf/buildlink3.mk"
BUILDLINK_API_DEPENDS.libXi+=	libXi>=1.7.8
.include "../../x11/libXi/buildlink3.mk"
BUILDLINK_API_DEPENDS.xfce4-panel+=	xfce4-panel>=4.18.0
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
