# $NetBSD: Makefile,v 1.6 2007/01/23 11:53:47 martti Exp $
#

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	2.2.9

DISTNAME=	gtk-xfce-engine-${XFCE4_VERSION}
PKGNAME=	xfce4-gtk2-engine-${XFCE4_VERSION}
#PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Xfce GTK2 themes

USE_DIRS+=	xdg-1.1

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.10.0

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
