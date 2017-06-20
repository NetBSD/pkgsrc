# $NetBSD: Makefile,v 1.39 2017/06/20 14:59:54 youri Exp $

PKGREVISION= 4
.include "../../meta-pkgs/xfce4/Makefile.common"

VERSION=	3.2.0
DISTNAME=	gtk-xfce-engine-${VERSION}
PKGNAME=	xfce4-gtk2-engine-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	http://archive.xfce.org/src/xfce/gtk-xfce-engine/3.2/

HOMEPAGE=	https://wiki.xfce.org/howto/gtk_theme
COMMENT=	Xfce GTK2 themes

MAKE_DIRS+=	${PREFIX}/share/themes/Xfce

CONFIGURE_ARGS+=--enable-gtk3

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
