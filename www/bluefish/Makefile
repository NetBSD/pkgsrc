# $NetBSD: Makefile,v 1.4 2000/08/16 05:38:35 jlam Exp $
#

DISTNAME=	bluefish-0.4
PKGNAME=	${DISTNAME}nb1
CATEGORIES=	www
MASTER_SITES=	http://bluefish.openoffice.nl/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://bluefish.openoffice.nl/

BUILD_DEPENDS+=	autoreconf:../../devel/autoconf
DEPENDS+=	gettext>=0.10.35nb1:../../devel/gettext
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	weblint-*:../../www/weblint

MANCOMPRESSED=	yes

USE_X11BASE=	# defined
USE_GMAKE=	# defined

GNU_CONFIGURE=	# defined
CONFIGURE_ENV+=	CPPFLAGS="${CPPFLAGS}"
CPPFLAGS+=	-I${LOCALBASE}/include

pre-configure:
	cd ${WRKSRC} && autoreconf

.include "../../mk/bsd.pkg.mk"
