# $NetBSD: Makefile,v 1.6 1999/08/28 09:43:16 rh Exp $
#

DISTNAME=	wmakerconf-2.1
CATEGORIES=	x11
MASTER_SITES=	http://www-info2.informatik.uni-wuerzburg.de/staff/ulli/wmakerconf/ \
		ftp://ftp.ema.fr/pub/mirrors/windowmaker/wmakerconf/
EXTRACT_SUFX=	.tar.bz2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		wmakerconf-data-0.60.0${EXTRACT_SUFX}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www-info2.informatik.uni-wuerzburg.de/staff/ulli/wmakerconf/

DEPENDS+=	windowmaker-0.60.0:../../x11/windowmaker
DEPENDS+=	imlib-1.9.4:../../graphics/imlib
DEPENDS+=	libproplist-0.8.3:../../devel/libproplist
DEPENDS+=	gtk+-1.2.4:../../x11/gtk

USE_X11BASE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS} -I${LOCALBASE}/include"
LDFLAGS+=	-L${LOCALBASE}/lib -R${LOCALBASE}/lib	# for libPropList.so.1.1

.include "../../mk/bsd.pkg.mk"
