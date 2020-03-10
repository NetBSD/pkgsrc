# $NetBSD: Makefile,v 1.19 2020/03/10 22:11:17 wiz Exp $

PKGREVISION= 2
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-indicator-applet-${VERSION:R}.1
CATEGORIES=	x11

COMMENT=	MATE indicator applet

.include "../../x11/mate-panel/buildlink3.mk"
.include "../../devel/libindicator/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
