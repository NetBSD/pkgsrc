# $NetBSD: Makefile,v 1.10 1999/10/05 21:07:06 tron Exp $
#

DISTNAME=	wmakerconf-2.2
CATEGORIES=	x11
MASTER_SITES=	http://www-info2.informatik.uni-wuerzburg.de/staff/ulli/wmakerconf/ \
		ftp://ftp.ema.fr/pub/mirrors/windowmaker/wmakerconf/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www-info2.informatik.uni-wuerzburg.de/staff/ulli/wmakerconf/

DEPENDS+=	imlib-1.9.4:../../graphics/imlib
DEPENDS+=	gtk+-1.2.4:../../x11/gtk
DEPENDS+=	windowmaker-*:../../x11/windowmaker

USE_X11BASE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib -R${LOCALBASE}/lib	# for libPropList.so.1.1

.include "../../mk/bsd.pkg.mk"
