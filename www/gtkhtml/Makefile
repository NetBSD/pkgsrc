# $NetBSD: Makefile,v 1.11 2001/09/27 23:18:52 jlam Exp $

DISTNAME=		gtkhtml-0.12.0
CATEGORIES=		www gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=unstable/sources/gtkhtml/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		lightweight HTML rendering/printing/editing engine

DEPENDS+=		gal>=0.5nb1:../../devel/gal
DEPENDS+=		glibwww-[0-9]*:../../www/glibwww
DEPENDS+=		bonobo>=0.37:../../devel/bonobo
DEPENDS+=		{control-center<1.5.0,libcapplet-[0-9]*}:../../x11/controlcenter
DEPENDS+=		gnome-print>=0.28:../../print/gnome-print
DEPENDS+=		libghttp>=1.0:../../www/libghttp

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_GMAKE=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CPPFLAGS+=		-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
