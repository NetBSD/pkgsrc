# $NetBSD: Makefile,v 1.22 2007/01/23 11:53:47 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	libxfcegui4-${XFCE4_VERSION}
PKGNAME=	libxfce4gui-${XFCE4_VERSION}
#PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Xfce widget library

USE_TOOLS+=	msgfmt

PKGCONFIG_OVERRIDE=	libxfcegui4/libxfcegui4-1.0.pc.in

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../databases/dbh/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libxfce4util/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
