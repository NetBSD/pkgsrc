# $NetBSD: Makefile,v 1.1.1.1 2004/06/21 06:19:46 martti Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.1.0

DISTNAME=	xfce4-windowlist-plugin-${XFCE4_VERSION}
CATEGORIES=	x11
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
COMMENT=	XFce4 window list plugin

WRKSRC=		${WRKDIR}/xfce4-windowlist-plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
