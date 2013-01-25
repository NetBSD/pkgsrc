# $NetBSD: Makefile,v 1.63 2013/01/25 19:18:09 reed Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/webkitgtk/webkit-gtk/}
PKGREVISION=	1

COMMENT=	GTK2 port of the WebKit browser engine

CONFIGURE_ARGS+=	--with-gtk=2.0
CONFIGURE_ARGS+=	--disable-webkit2

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
