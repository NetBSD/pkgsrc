# $NetBSD: Makefile,v 1.19 2005/05/18 06:10:31 martti Exp $
#

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	2.2.7

DISTNAME=	gtk-xfce-engine-${XFCE4_VERSION}
PKGNAME=	xfce4-gtk2-engine-${XFCE4_VERSION}
#PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	XFce4 GTK2 themes

USE_DIRS+=	xdg-1.1

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
