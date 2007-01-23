# $NetBSD: Makefile,v 1.15 2007/01/23 11:53:47 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce-mcs-plugins-${XFCE4_VERSION}
PKGNAME=	xfce4-mcs-plugins-${XFCE4_VERSION}
#PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Xfce settings manager plugins

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xfce4-mcs-manager/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
