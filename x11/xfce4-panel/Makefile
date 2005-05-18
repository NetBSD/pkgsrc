# $NetBSD: Makefile,v 1.16 2005/05/18 06:10:31 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce4-panel-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	XFce4 panel

PKGCONFIG_OVERRIDE=	panel/xfce4-panel-1.0.pc.in
PTHREAD_AUTO_VARS=	yes

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../x11/xfce4-mcs-plugins/buildlink3.mk"
.include "../../x11/startup-notification/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
