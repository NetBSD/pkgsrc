# $NetBSD: Makefile,v 1.13 2000/01/02 01:03:53 wiz Exp $
#

DISTNAME=	wmakerconf-2.4
CATEGORIES=	x11
MASTER_SITES=	http://ulli.linuxbox.com/wmakerconf/
EXTRACT_SUFX=	.tar.bz2

PATCHFILES=	wmakerconf-2.4.patch
PATCH_SITES=	${MASTER_SITES}
PATCH_DIST_STRIP=	-p1

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://ulli.linuxbox.com/wmakerconf/

DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	windowmaker-*:../../x11/windowmaker

USE_X11BASE=	yes
USE_PERL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

# for libintl and libProplist
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
