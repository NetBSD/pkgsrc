# $NetBSD: Makefile,v 1.75 2013/06/09 13:22:55 obache Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/webkitgtk/webkit-gtk/}
PKGREVISION=	8

COMMENT=	GTK2 port of the WebKit browser engine

CONFIGURE_ARGS+=	--with-gtk=2.0
CONFIGURE_ARGS+=	--disable-webkit2

#introspection support
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.24.17nb3
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
