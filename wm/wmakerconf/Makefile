# $NetBSD: Makefile,v 1.1.1.1 2000/12/15 23:25:17 wiz Exp $
#

DISTNAME=	wmakerconf-2.7
CATEGORIES=	x11 wm
MASTER_SITES=	http://ulli.linuxave.net/wmakerconf/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wiz@netbsd.org
HOMEPAGE=	http://ulli.linuxave.net/wmakerconf/

DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	windowmaker-*:../../wm/windowmaker

USE_X11BASE=	yes
USE_PERL5=	yes
USE_LIBINTL=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"

# for libProplist
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-Wl,-R${LOCALBASE}/lib -L${LOCALBASE}/lib

.include "../../mk/bsd.pkg.mk"
