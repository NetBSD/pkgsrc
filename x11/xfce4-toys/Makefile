# $NetBSD: Makefile,v 1.16 2007/01/18 15:26:53 joerg Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-toys-${XFCE4_VERSION}
PKGREVISION=	3
CATEGORIES=	x11
COMMENT=	Xfce toys

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
