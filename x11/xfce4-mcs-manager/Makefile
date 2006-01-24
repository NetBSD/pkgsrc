# $NetBSD: Makefile,v 1.13 2006/01/24 07:33:01 wiz Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

DISTNAME=	xfce-mcs-manager-${XFCE4_VERSION}
PKGNAME=	xfce4-mcs-manager-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Xfce settings manager

PKGCONFIG_OVERRIDE=	xfce-mcs-manager/xfce-mcs-manager.pc.in
PTHREAD_AUTO_VARS=	yes

.include "../../x11/libxfce4gui/buildlink3.mk"
.include "../../x11/libxfce4mcs/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
