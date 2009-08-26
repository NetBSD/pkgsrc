# $NetBSD: Makefile,v 1.12 2009/08/26 19:56:56 sno Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	2.4.3

DISTNAME=	gtk-xfce-engine-${XFCE4_VERSION}
PKGNAME=	xfce4-gtk2-engine-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Xfce GTK2 themes


.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
