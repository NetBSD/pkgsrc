# $NetBSD: Makefile,v 1.33 2024/04/07 07:35:24 wiz Exp $

PKGREVISION= 7
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-indicator-applet-${VERSION:R}.0
CATEGORIES=	x11

COMMENT=	MATE indicator applet

.include "../../x11/mate-panel/buildlink3.mk"
.include "../../devel/libindicator/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
