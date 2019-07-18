# $NetBSD: Makefile,v 1.44 2019/07/18 08:15:39 nia Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	1.8.0
DISTNAME=	xfce4-places-plugin-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-places-plugin/${VERSION:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-places-plugin
COMMENT=	Xfce Places plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
