# $NetBSD: Makefile,v 1.18 2001/09/27 23:18:52 jlam Exp $

DISTNAME=	bluefish-0.6
CATEGORIES=	www
MASTER_SITES=	http://pkedu.fbt.eitn.wau.nl/~olivier/downloads/	\
		http://student.wau.nl/~olivier/bluefish/download/	\
		ftp://bluefish.advancecreations.com/pub/bluefish/downloads/ \
		http://bluefish.mrball.net/downloads/			\
		ftp://ftp.ratisbona.com/pub/bluefish/downloads/		\
		http://bluefish.shellhung.org/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	wulf@ping.net.au
HOMEPAGE=	http://bluefish.openoffice.nl/
COMMENT=	GTK HTML editor for the experienced web designer

BUILD_DEPENDS+=	autoconf>=2.13:../../devel/autoconf
BUILD_USES_MSGFMT=	YES
DEPENDS+=	gtk+-1.2.*:../../x11/gtk
DEPENDS+=	imlib-[0-9]*:../../graphics/imlib
DEPENDS+=	weblint-[0-9]*:../../www/weblint

USE_X11BASE=	# defined
USE_GMAKE=	# defined
USE_LIBINTL=	# defined

GNU_CONFIGURE=	# defined

HTMLDIR=	${PREFIX}/share/doc/html/bluefish

pre-configure:
	cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${CP} -R ${WRKSRC}/manual/* ${HTMLDIR}
	@${ECHO} Setting permissions on HTML documentation...
	${CHOWN} -R root.wheel ${HTMLDIR}
	${FIND} ${HTMLDIR} -type d -exec ${CHMOD} 555 {} \;
	${FIND} ${HTMLDIR} -type f -exec ${CHMOD} 444 {} \;

.include "../../mk/bsd.pkg.mk"
