# $NetBSD: Makefile,v 1.23 2022/08/11 05:09:35 gutteridge Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-indicator-plugin-2.4.1
CATEGORIES=	x11
MASTER_SITES=	https://archive.xfce.org/src/panel-plugins/xfce4-indicator-plugin/2.4/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-indicator-plugin
COMMENT=	Xfce indicator plugin

.include "../../devel/libindicator/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
