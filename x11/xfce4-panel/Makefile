# $NetBSD: Makefile,v 1.12 2004/11/12 06:39:21 jlam Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-panel-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	XFce4 panel

PKGCONFIG_OVERRIDE=	panel/xfce4-panel-1.0.pc.in

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
