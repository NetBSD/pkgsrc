# $NetBSD: Makefile,v 1.1 2016/05/21 18:57:23 youri Exp $

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
