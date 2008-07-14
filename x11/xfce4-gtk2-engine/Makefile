# $NetBSD: Makefile,v 1.9 2008/07/14 12:56:19 joerg Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	2.4.2

DISTNAME=	gtk-xfce-engine-${XFCE4_VERSION}
PKGNAME=	xfce4-gtk2-engine-${XFCE4_VERSION}
CATEGORIES=	x11
COMMENT=	Xfce GTK2 themes

USE_DIRS+=	xdg-1.1

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
