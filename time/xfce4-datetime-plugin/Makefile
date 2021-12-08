# $NetBSD: Makefile,v 1.62 2021/12/08 16:06:49 adam Exp $

PKGREVISION= 1
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	0.8.1
DISTNAME=	xfce4-datetime-plugin-${VERSION}
CATEGORIES=	time
MASTER_SITES=	https://archive.xfce.org/src/panel-plugins/xfce4-datetime-plugin/${VERSION:R}/

HOMEPAGE=	https://goodies.xfce.org/projects/panel-plugins/xfce4-datetime-plugin
COMMENT=	Xfce calendar plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
