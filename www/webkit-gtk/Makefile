# $NetBSD: Makefile,v 1.71 2013/05/31 12:42:55 wiz Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/webkitgtk/webkit-gtk/}
PKGREVISION=	4

COMMENT=	GTK2 port of the WebKit browser engine

CONFIGURE_ARGS+=	--with-gtk=2.0
CONFIGURE_ARGS+=	--disable-webkit2

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
