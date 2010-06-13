# $NetBSD: Makefile,v 1.14 2010/06/13 22:45:55 wiz Exp $

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	2.6.0

DISTNAME=	gtk-xfce-engine-${XFCE4_VERSION}
PKGNAME=	xfce4-gtk2-engine-${XFCE4_VERSION}
PKGREVISION=	1
CATEGORIES=	x11
COMMENT=	Xfce GTK2 themes

MAKE_DIRS+=	${PREFIX}/share/themes/Xfce

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
