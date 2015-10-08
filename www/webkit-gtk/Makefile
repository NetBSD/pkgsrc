# $NetBSD: Makefile,v 1.97.2.1 2015/10/08 00:12:56 spz Exp $

PKGREVISION= 2
.include "Makefile.common"

PKGNAME=	${DISTNAME:S/webkitgtk/webkit-gtk/}

COMMENT=	GTK port of the WebKit browser engine

BUILD_DEPENDS+=	gettext-tools>=0.18:../../devel/gettext-tools

# shm_open(3) and shm_unlink(3) appeared in NetBSD 7.0
NOT_FOR_PLATFORM=	NetBSD-[1-6]*-*

#introspection support
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.24.17nb3
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../sysutils/libnotify/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
