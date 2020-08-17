# $NetBSD: Makefile,v 1.35 2020/08/17 20:17:48 leot Exp $

PKGREVISION= 30
.include "Makefile.common"

PKGNAME=	${DISTNAME:S/webkitgtk/webkit24-gtk/}

COMMENT=	GTK2 port of the WebKit browser engine (version 2.4)

CONFIGURE_ARGS+=	--with-gtk=2.0
CONFIGURE_ARGS+=	--disable-webkit2

#introspection support
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.24.17nb3
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
