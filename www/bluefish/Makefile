# $NetBSD: Makefile,v 1.13 2001/02/17 17:21:58 wiz Exp $
#

DISTNAME=	bluefish-0.6
CATEGORIES=	www
MASTER_SITES=	http://bluefish.openoffice.nl/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://bluefish.openoffice.nl/
COMMENT=	GTK HTML editor for the experienced web designer

BUILD_DEPENDS+=	${LOCALBASE}/bin/autoreconf:../../devel/autoconf
BUILD_DEPENDS+=	msgfmt:../../devel/gettext
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	imlib-*:../../graphics/imlib
DEPENDS+=	weblint-*:../../www/weblint

USE_X11BASE=	# defined
USE_GMAKE=	# defined
USE_LIBINTL=	# defined

GNU_CONFIGURE=	# defined

HTMLDIR=	${PREFIX}/share/doc/html/bluefish

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	cd ${WRKSRC}/manual; ${CP} -r * ${HTMLDIR}
	@echo Setting permissions on HTML documentation...
	${CHOWN} -R root.wheel ${HTMLDIR}
	${FIND} ${HTMLDIR} -type d -exec ${CHMOD} 555 {} \;
	${FIND} ${HTMLDIR} -type f -exec ${CHMOD} 444 {} \;

.include "../../mk/bsd.pkg.mk"
