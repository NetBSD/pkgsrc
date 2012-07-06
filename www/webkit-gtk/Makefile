# $NetBSD: Makefile,v 1.56 2012/07/06 14:03:50 drochner Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/webkit/webkit-gtk/}
PKGREVISION=	2

COMMENT=	GTK2 port of the WebKit browser engine

CONFIGURE_ARGS+=	--with-gtk=2.0

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
