# $NetBSD: Makefile,v 1.4 2006/01/24 07:33:02 wiz Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	0.1.0

DISTNAME=	xfce4-windowlist-plugin-${XFCE4_VERSION}
PKGREVISION=	2
CATEGORIES=	x11
MASTER_SITES=	http://download.berlios.de/xfce-goodies/
COMMENT=	Xfce window list plugin

WRKSRC=		${WRKDIR}/xfce4-windowlist-plugin

.include "../../x11/xfce4-panel/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
