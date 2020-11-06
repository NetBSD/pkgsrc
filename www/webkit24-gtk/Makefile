# $NetBSD: Makefile,v 1.38 2020/11/06 15:30:10 nia Exp $

PKGREVISION= 33
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
