# $NetBSD: Makefile,v 1.87 2015/03/31 15:56:29 joerg Exp $

.include "Makefile.common"

PKGNAME=	${DISTNAME:S/webkitgtk/webkit-gtk/}

COMMENT=	GTK2 port of the WebKit browser engine

CONFIGURE_ARGS+=	--with-gtk=2.0
CONFIGURE_ARGS+=	--disable-webkit2

.if ${OPSYS} == "NetBSD" && ${MACHINE_CPU:U} == "arm"
LDFLAGS+=	-Wl,-no-keep-memory -Wl,-reduce-memory
.endif

#introspection support
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.24.17nb3
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
