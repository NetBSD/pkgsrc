# $NetBSD: Makefile,v 1.17 2000/11/29 23:50:21 wiz Exp $
#

DISTNAME=	wmakerconf-2.7
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
USE_LIBINTL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

# for libProplist
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
