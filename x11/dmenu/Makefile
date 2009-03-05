# $NetBSD: Makefile,v 1.3 2009/03/05 09:26:18 ghen Exp $

DISTNAME=		dmenu-3.9
CATEGORIES=		x11
MASTER_SITES=		http://code.suckless.org/dl/tools/

MAINTAINER=		ghen@NetBSD.org
HOMEPAGE=		http://www.suckless.org/wiki/tools/xlib
COMMENT=		Dymanic menu for wmii

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../x11/xineramaproto/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
