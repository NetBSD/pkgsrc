# $NetBSD: Makefile,v 1.1.1.1.2.2 2004/07/14 11:17:20 agc Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.1.0

DISTNAME=	xfce4-taskbar-plugin-${XFCE4_VERSION}
CATEGORIES=	sysutils
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
COMMENT=	XFce4 taskbar plugin

WRKSRC=		${WRKDIR}/xfce4-taskbar-plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
