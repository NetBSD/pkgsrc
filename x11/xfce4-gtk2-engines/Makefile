# $NetBSD: Makefile,v 1.17 2005/03/18 07:59:09 martti Exp $
#

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	2.2.6

DISTNAME=	gtk-xfce-engine-${XFCE4_VERSION}
PKGNAME=	xfce4-gtk2-engine-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	XFce4 GTK2 themes

USE_DIRS+=	xdg-1.1

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
