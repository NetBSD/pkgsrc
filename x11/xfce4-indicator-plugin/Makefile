# $NetBSD: Makefile,v 1.16 2020/03/08 16:51:52 wiz Exp $

PKGREVISION= 7
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-indicator-plugin-2.3.4
CATEGORIES=	x11
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-indicator-plugin/2.3/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-indicator-plugin
COMMENT=	Xfce indicator plugin

.include "../../devel/libindicator/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
