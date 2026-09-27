# $NetBSD: Makefile,v 1.43 2026/09/27 11:39:28 tnn Exp $

PKGREVISION= 17
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-indicator-applet-${VERSION:R}.0
CATEGORIES=	x11

COMMENT=	MATE indicator applet

.include "../../x11/mate-panel/buildlink3.mk"
.include "../../devel/libindicator/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
