# $NetBSD: Makefile,v 1.4 2002/11/13 19:26:36 wiz Exp $
#

DISTNAME=	make_album_1_6
PKGNAME=	make_album-1.6
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://www.burren.cx/david/files/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://www.burren.cx/david/make_album.html
COMMENT=	Generate HTML albums of images

MY_SCRIPTS=	index_albums ingest make_album newimagedir populate_master

USE_BUILDLINK2=	# defined
USE_PERL5=	# defined
REPLACE_PERL=	${MY_SCRIPTS}

NO_BUILD=	# defined

do-install:
	for f in ${MY_SCRIPTS}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$f ${PREFIX}/bin; \
	done
	${INSTALL_DATA} ${WRKSRC}/cameras.txt ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/make_album
	for f in CHANGES README TODO; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${PREFIX}/share/doc/make_album; \
	done

.include "../../graphics/ImageMagick/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
