# $NetBSD: Makefile,v 1.11 1999/10/09 01:06:13 jlam Exp $
#

DISTNAME=	wmakerconf-2.3
CATEGORIES=	x11
MASTER_SITES=	http://members.linuxstart.com/~ulli/wmakerconf/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://members.linuxstart.com/~ulli/wmakerconf/

DEPENDS+=	imlib-1.9.4:../../graphics/imlib
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
