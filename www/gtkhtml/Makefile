# $NetBSD: Makefile,v 1.7 2001/06/11 06:34:54 jlam Exp $
#

DISTNAME=	gtkhtml-0.8.3
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/gtkhtml/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	lightweight HTML rendering/printing/editing engine

DEPENDS+=	gal>=0.5nb1:../../devel/gal
DEPENDS+=	glibwww-*:../../www/glibwww
DEPENDS+=	bonobo>=0.37:../../devel/bonobo
DEPENDS+=	control-center>=1.4.0:../../x11/controlcenter
DEPENDS+=	gnome-print>=0.28:../../print/gnome-print
DEPENDS+=	libghttp>=1.0:../../www/libghttp

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig
CPPFLAGS+=	-I${LOCALBASE}/include

.include "../../mk/bsd.pkg.mk"
