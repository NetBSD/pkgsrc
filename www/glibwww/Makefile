# $NetBSD: Makefile,v 1.1.1.1 2000/11/07 05:09:18 rh Exp $
#

DISTNAME=	glibwww-0.2
CATEGORIES=	www gnome devel
MASTER_SITES=	${MASTER_SITE_GNOME:=unstable/sources/glibwww/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	libwww>=5.2.8:../../www/libwww
DEPENDS+=	gnome-libs>=1.2.3:../../x11/gnome-libs

GNU_CONFIGURE=	YES
USE_LIBTOOL=	YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
