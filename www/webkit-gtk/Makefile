# $NetBSD: Makefile,v 1.61 2012/10/08 23:00:50 adam Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/webkit/webkit-gtk/}
PKGREVISION=	4

COMMENT=	GTK2 port of the WebKit browser engine

CONFIGURE_ARGS+=	--with-gtk=2.0

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
