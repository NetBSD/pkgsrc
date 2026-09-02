# $NetBSD: Makefile,v 1.41 2026/09/02 19:05:35 wiz Exp $

PKGREVISION= 6
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-indicator-plugin-2.4.3
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/panel-plugins/xfce4-indicator-plugin/2.4/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-indicator-plugin
COMMENT=	Xfce indicator plugin

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/libayatana-indicator/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
