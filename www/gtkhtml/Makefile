# $NetBSD: Makefile,v 1.2 2000/09/02 06:56:17 rh Exp $
#

DISTNAME=	gtkhtml-0.6.1
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/gtkhtml/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	libwww>=5.2.8:../../www/libwww
DEPENDS+=	bonobo>=0.15:../../devel/bonobo
DEPENDS+=	control-center>=1.2.0:../../x11/controlcenter
DEPENDS+=	gnome-print>=0.20:../../print/gnome-print

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"

.include "../../mk/bsd.pkg.mk"
