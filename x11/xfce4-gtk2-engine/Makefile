# $NetBSD: Makefile,v 1.46 2018/05/15 22:45:10 youri Exp $

PKGREVISION=	8

VERSION=	3.2.0
DISTNAME=	gtk-xfce-engine-${VERSION}
PKGNAME=	xfce4-gtk2-engine-${VERSION}
CATEGORIES=	x11
MASTER_SITES=	http://archive.xfce.org/src/xfce/gtk-xfce-engine/3.2/
EXTRACT_SUFX=	.tar.bz2

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config msgfmt perl intltool

HOMEPAGE=	https://wiki.xfce.org/howto/gtk_theme
COMMENT=	Xfce GTK2 themes
LICENSE=	gnu-gpl-v2

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
