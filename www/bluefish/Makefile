# $NetBSD: Makefile,v 1.21 2002/01/19 16:59:52 wiz Exp $

DISTNAME=	bluefish-0.7
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

DEPENDS+=	gtk+>=1.2.7:../../x11/gtk
DEPENDS+=	imlib-[0-9]*:../../graphics/imlib
DEPENDS+=	weblint-[0-9]*:../../www/weblint
DEPENDS+=	jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-[0-9]*:../../graphics/png
DEPENDS+=	tiff-[0-9]*:../../graphics/tiff
DEPENDS+=	gnome-libs-[0-9]*:../../x11/gnome-lib
DEPENDS+=	gdk-pixbuf-[0-9]*:../../graphics/gdk-pixbuf

BUILD_USES_MSGFMT=	YES

USE_X11BASE=	# defined
USE_GMAKE=	# defined
USE_LIBINTL=	# defined

CONFIGURE_ARGS+=	--with-autocomplet

GNU_CONFIGURE=	# defined

HTMLDIR=	${PREFIX}/share/doc/html/bluefish

# pre-configure:
# 	cd ${WRKSRC} && ${LOCALBASE}/bin/autoreconf

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${CP} -R ${WRKSRC}/manual/* ${HTMLDIR}
	@${ECHO} Setting permissions on HTML documentation...
	${CHOWN} -R ${ROOT_USER}:${ROOT_GROUP} ${HTMLDIR}
	${FIND} ${HTMLDIR} -type d -exec ${CHMOD} 555 {} \;
	${FIND} ${HTMLDIR} -type f -exec ${CHMOD} 444 {} \;

.include "../../mk/bsd.pkg.mk"
