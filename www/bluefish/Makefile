# $NetBSD: Makefile,v 1.26 2002/10/21 15:41:52 wiz Exp $

DISTNAME=	bluefish-0.7
PKGREVISION=	1
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

DEPENDS+=	weblint-[0-9]*:../../www/weblint

BUILD_USES_MSGFMT=	YES

USE_BUILDLINK2=	# defined
USE_X11BASE=	# defined
USE_GMAKE=	# defined

CONFIGURE_ARGS+=	--with-autocomplet

GNU_CONFIGURE=	# defined

HTMLDIR=	${PREFIX}/share/doc/html/bluefish

post-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${CP} -R ${WRKSRC}/manual/* ${HTMLDIR}
	@${ECHO} Setting permissions on HTML documentation...
	${CHOWN} -R ${ROOT_USER}:${ROOT_GROUP} ${HTMLDIR}
	${FIND} ${HTMLDIR} -type d -exec ${CHMOD} 555 {} \;
	${FIND} ${HTMLDIR} -type f -exec ${CHMOD} 444 {} \;

.include "../../graphics/gdk-pixbuf/buildlink2.mk"
.include "../../x11/gnome-libs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
