# $NetBSD: Makefile,v 1.7 2000/08/25 05:51:13 jlam Exp $
#

DISTNAME=	bluefish-0.5
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

HTMLDIR=	${PREFIX}/share/doc/html/bluefish

pre-configure:
	cd ${WRKSRC} && autoreconf

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/manual; ${INSTALL_DATA} * ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
