# $NetBSD: Makefile,v 1.3 2000/12/31 14:04:43 rh Exp $
#

DISTNAME=	gtkhtml-0.8
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/gtkhtml/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	gal>=0.4.1:../../devel/gal
DEPENDS+=	glibwww-*:../../www/glibwww
DEPENDS+=	bonobo>=0.29:../../devel/bonobo
DEPENDS+=	control-center>=1.2.0:../../x11/controlcenter
DEPENDS+=	gnome-print>=0.20:../../print/gnome-print

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=${WRKSRC}/ltconfig
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
