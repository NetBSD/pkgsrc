# $NetBSD: Makefile,v 1.4 2006/04/17 13:46:10 wiz Exp $
#

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	2.2.8

DISTNAME=	gtk-xfce-engine-${XFCE4_VERSION}
PKGNAME=	xfce4-gtk2-engine-${XFCE4_VERSION}
#PKGREVISION=	1
PKGREVISION=	3
CATEGORIES=	x11
COMMENT=	Xfce GTK2 themes

USE_DIRS+=	xdg-1.1

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
