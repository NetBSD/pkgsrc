# $NetBSD: Makefile,v 1.6 2015/10/10 01:57:56 ryoon Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/webkitgtk/webkit-gtk/}
PKGREVISION=	22

COMMENT=	GTK2 port of the WebKit browser engine (v1)

CONFIGURE_ARGS+=	--with-gtk=2.0
CONFIGURE_ARGS+=	--disable-webkit2

#introspection support
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.24.17nb3
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
