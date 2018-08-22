# $NetBSD: Makefile,v 1.23 2018/08/22 09:47:26 wiz Exp $
#

DISTNAME=	make_album_1_6
PKGNAME=	make_album-1.6
PKGREVISION=	12
CATEGORIES=	www
MASTER_SITES=	http://www.burren.cx/david/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.burren.cx/david/make_album.html
COMMENT=	Generate HTML albums of images

DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

MY_SCRIPTS=	index_albums ingest make_album newimagedir populate_master

USE_TOOLS+=	perl:run
REPLACE_PERL=	${MY_SCRIPTS}

# do not disable configure stage via NO_CONFIGURE - REPLACE_PERL is handled
# in pre-configure stage
NO_BUILD=	yes

INSTALLATION_DIRS=	bin lib share/doc/make_album

do-install:
	for f in ${MY_SCRIPTS}; do \
		${INSTALL_SCRIPT} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/bin; \
	done
	${INSTALL_DATA} ${WRKSRC}/cameras.txt ${DESTDIR}${PREFIX}/lib
	for f in CHANGES README TODO; do \
		${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/share/doc/make_album; \
	done

.include "../../mk/bsd.pkg.mk"
