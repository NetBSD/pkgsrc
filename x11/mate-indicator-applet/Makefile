# $NetBSD: Makefile,v 1.2 2016/08/03 10:23:36 adam Exp $

PKGREVISION= 1
.include "../../meta-pkgs/mate/Makefile.common"

DISTNAME=	mate-indicator-applet-${MATE_VERSION}
CATEGORIES=	x11

COMMENT=	MATE indicator applet

.include "../../x11/mate-panel/buildlink3.mk"
.include "../../devel/libindicator/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
