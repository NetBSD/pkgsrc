# $NetBSD: Makefile,v 1.3 2003/12/13 00:45:27 wiz Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-panel-${XFCE4_VERSION}
PKGREVISION=	2
CATEGORIES=	x11
COMMENT=	XFce4 panel

PKGCONFIG_OVERRIDE=	panel/xfce4-panel-1.0.pc.in

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink2.mk"
.include "../../x11/startup-notification/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
