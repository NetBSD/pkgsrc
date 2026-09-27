# $NetBSD: Makefile,v 1.5 2026/09/27 11:39:15 tnn Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-ximagesrc/}
PKGREVISION=	2
CATEGORIES=	x11 gnome

COMMENT=	Open source multimedia framework - X11 image plugin

GST_PLUGINS+=	ximagesrc

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
