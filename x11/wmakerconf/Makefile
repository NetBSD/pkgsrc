# $NetBSD: Makefile,v 1.15 2000/04/08 08:41:26 rh Exp $
#

DISTNAME=	wmakerconf-2.6.1
CATEGORIES=	x11
MASTER_SITES=	http://ulli.linuxave.net/wmakerconf/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://ulli.linuxave.net/wmakerconf/

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
