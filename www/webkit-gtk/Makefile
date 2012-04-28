# $NetBSD: Makefile,v 1.54 2012/04/28 14:12:16 drochner Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/webkit/webkit-gtk/}

COMMENT=	GTK2 port of the WebKit browser engine

CONFIGURE_ARGS+=	--with-gtk=2.0

.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
