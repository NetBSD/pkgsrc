# $NetBSD: Makefile,v 1.13 2001/10/05 07:00:21 rh Exp $

DISTNAME=		gtkhtml-0.14.0
CATEGORIES=		www gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/gtkhtml/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		lightweight HTML rendering/printing/editing engine

DEPENDS+=		glibwww-[0-9]*:../../www/glibwww
DEPENDS+=		{control-center<1.5.0,libcapplet-[0-9]*}:../../x11/controlcenter

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../print/gnome-print/buildlink.mk"
.include "../../www/libghttp/buildlink.mk"
.include "../../devel/bonobo/buildlink.mk"
.include "../../devel/gal/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
