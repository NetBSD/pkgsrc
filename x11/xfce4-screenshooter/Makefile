# $NetBSD: Makefile,v 1.80 2026/04/20 05:22:21 wiz Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	1.11.3
DISTNAME=	xfce4-screenshooter-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/apps/xfce4-screenshooter/${VERSION:R}/
EXTRACT_SUFX=	.tar.xz

HOMEPAGE=	https://archive.xfce.org/src/apps/xfce4-screenshooter/${VERSION:R}/
COMMENT=	Xfce screenshot application

DEPENDS+=	zenity3-[0-9]*:../../x11/zenity3
TOOL_DEPENDS+=	help2man-[0-9]*:../../converters/help2man

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/xfce4-conf/buildlink3.mk"
BUILDLINK_API_DEPENDS.libXi+=	libXi>=1.7.8
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/libxfce4ui/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
