# $NetBSD: Makefile,v 1.29 2013/06/04 22:17:34 tron Exp $

.include "../../meta-pkgs/xfce4/Makefile.common"

XFCE4_VERSION=	2.6.0

DISTNAME=	gtk-xfce-engine-${XFCE4_VERSION}
PKGNAME=	xfce4-gtk2-engine-${XFCE4_VERSION}
PKGREVISION=	15
CATEGORIES=	x11
COMMENT=	Xfce GTK2 themes

MAKE_DIRS+=	${PREFIX}/share/themes/Xfce

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
