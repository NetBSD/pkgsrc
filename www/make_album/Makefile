# $NetBSD: Makefile,v 1.9 2005/06/17 03:50:41 jlam Exp $
#

DISTNAME=	make_album_1_6
PKGNAME=	make_album-1.6
PKGREVISION=	4
CATEGORIES=	www
MASTER_SITES=	http://www.burren.cx/david/files/

MAINTAINER=	lukem@NetBSD.org
HOMEPAGE=	http://www.burren.cx/david/make_album.html
COMMENT=	Generate HTML albums of images

DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

MY_SCRIPTS=	index_albums ingest make_album newimagedir populate_master

USE_PERL5=	# defined
REPLACE_PERL=	${MY_SCRIPTS}

NO_CONFIGURE=	# defined
NO_BUILD=	# defined

INSTALLATION_DIRS=	bin lib

do-install:
	for f in ${MY_SCRIPTS}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$f ${PREFIX}/bin; \
	done
	${INSTALL_DATA} ${WRKSRC}/cameras.txt ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/make_album
	for f in CHANGES README TODO; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/make_album; \
	done

.include "../../mk/bsd.pkg.mk"
