# $NetBSD: Makefile,v 1.9 2000/12/28 14:40:40 wulf Exp $
#

DISTNAME=	bluefish-0.6
CATEGORIES=	www
MASTER_SITES=	http://bluefish.openoffice.nl/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://bluefish.openoffice.nl/

BUILD_DEPENDS+=	autoconf:../../devel/autoconf
DEPENDS+=	gettext>=0.10.35nb1:../../devel/gettext
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	weblint-*:../../www/weblint

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
	cd ${WRKSRC}/manual; ${CP} -r * ${HTMLDIR}
	@echo Setting permissions on HTML documentation...
	${CHOWN} -R root.wheel ${HTMLDIR}
	${FIND} ${HTMLDIR} -type d -exec ${CHMOD} 555 {} \;
	${FIND} ${HTMLDIR} -type f -exec ${CHMOD} 444 {} \;

.include "../../mk/bsd.pkg.mk"
