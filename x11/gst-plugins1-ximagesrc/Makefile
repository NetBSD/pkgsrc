# $NetBSD: Makefile,v 1.2 2025/10/23 20:39:55 wiz Exp $

PKGNAME=	${DISTNAME:S/plugins/plugins1/:S/-good/-ximagesrc/}
PKGREVISION=	1
CATEGORIES=	x11 gnome

COMMENT=	Open source multimedia framework - X11 image plugin

GST_PLUGINS+=	ximagesrc

.include "../../multimedia/gst-plugins1-good/Makefile.common"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
