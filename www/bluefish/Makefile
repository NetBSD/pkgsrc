# $NetBSD: Makefile,v 1.8 2000/12/28 14:08:45 wulf Exp $
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
	cd ${WRKSRC}/manual && \
	${INSTALL_DATA_DIR} ${HTMLDIR}/de && \
	${INSTALL_DATA} de/* ${HTMLDIR}/de && \
	${INSTALL_DATA_DIR} ${HTMLDIR}/en && \
	${INSTALL_DATA} en/* ${HTMLDIR}/en && \
	${INSTALL_DATA_DIR} ${HTMLDIR}/it && \
	${INSTALL_DATA} it/* ${HTMLDIR}/it && \
	${INSTALL_DATA_DIR} ${HTMLDIR}/hu && \
	${INSTALL_DATA} hu/* ${HTMLDIR}/hu && \
	${INSTALL_DATA_DIR} ${HTMLDIR}/images && \
	${INSTALL_DATA} images/* ${HTMLDIR}/images && \
	${INSTALL_DATA} index.html ${HTMLDIR} && \
	${INSTALL_DATA} manual.css ${HTMLDIR}

.include "../../mk/bsd.pkg.mk"
