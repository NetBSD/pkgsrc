# $NetBSD: Makefile,v 1.2 2016/08/03 10:23:39 adam Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-indicator-plugin-2.3.3
CATEGORIES=	x11
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-indicator-plugin/2.3/

HOMEPAGE=	http://goodies.xfce.org/projects/panel-plugins/xfce4-indicator-plugin
COMMENT=	Xfce indicator plugin

.include "../../devel/libindicator3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
