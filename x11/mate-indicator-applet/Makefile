# $NetBSD: Makefile,v 1.34 2024/10/20 14:04:53 wiz Exp $

PKGREVISION= 8
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-indicator-applet-${VERSION:R}.0
CATEGORIES=	x11

COMMENT=	MATE indicator applet

.include "../../x11/mate-panel/buildlink3.mk"
.include "../../devel/libindicator/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
