# $NetBSD: Makefile,v 1.11 2004/04/14 16:15:30 jmmv Exp $
#

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	2.1.9

DISTNAME=	gtk-xfce-engine-${XFCE4_VERSION}
PKGNAME=	xfce4-gtk2-engine-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	XFce4 GTK2 themes

USE_DIRS+=	xdg-1.1

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
