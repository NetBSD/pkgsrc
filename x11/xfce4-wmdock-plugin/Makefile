# $NetBSD: Makefile,v 1.16 2020/03/08 16:51:53 wiz Exp $
#
PKGREVISION= 12
.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-wmdock-plugin-0.6.0
CATEGORIES=	x11
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-wmdock-plugin/0.6/

HOMEPAGE=		https://goodies.xfce.org/projects/panel-plugins/xfce4-wmdock-plugin
COMMENT=		Xfce wmdock plugin

USE_FEATURES+=		strnlen

.include "../../devel/libwnck/buildlink3.mk"
.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
