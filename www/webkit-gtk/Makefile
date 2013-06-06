# $NetBSD: Makefile,v 1.74 2013/06/06 12:53:59 wiz Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/webkitgtk/webkit-gtk/}
PKGREVISION=	7

COMMENT=	GTK2 port of the WebKit browser engine

CONFIGURE_ARGS+=	--with-gtk=2.0
CONFIGURE_ARGS+=	--disable-webkit2

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
