# $NetBSD: Makefile,v 1.16 2000/08/26 17:15:06 veego Exp $
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
USE_PERL5=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

# for libintl and libProplist
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
