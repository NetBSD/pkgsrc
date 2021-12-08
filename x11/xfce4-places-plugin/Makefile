# $NetBSD: Makefile,v 1.53 2021/12/08 16:07:16 adam Exp $

PKGREVISION= 6
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	1.8.1
DISTNAME=	xfce4-places-plugin-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	http://archive.xfce.org/src/panel-plugins/xfce4-places-plugin/${VERSION:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-places-plugin
COMMENT=	Xfce Places plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../x11/xfce4-exo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
