# $NetBSD: Makefile,v 1.59 2012/10/02 17:12:10 tron Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/webkit/webkit-gtk/}
PKGREVISION=	2

COMMENT=	GTK2 port of the WebKit browser engine

CONFIGURE_ARGS+=	--with-gtk=2.0

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
