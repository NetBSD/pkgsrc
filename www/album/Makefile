# $NetBSD $
#

DISTNAME=	album
PKGREVISION=	1
ALBUMREV=	3.07
PKGNAME=	${DISTNAME}-${ALBUMREV}
CATEGORIES=	www
MASTER_SITES=	http://marginalhacks.com/bin/

MAINTAINER=	augustss@NetBSD.org
HOMEPAGE=	http://marginalhacks.com/Hacks/album/
COMMENT=	Generate HTML albums of images

DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	jhead-[2-9]*:../../graphics/jhead
DEPENDS+=	ffmpeg*:../../multimedia/ffmpeg

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MY_SCRIPT=	album

USE_PERL5=	# defined
REPLACE_PERL=	${MY_SCRIPT}

NO_CONFIGURE=	# defined
NO_BUILD=	# defined

do-install:	replace-interpreter
	${INSTALL_SCRIPT} ${WRKSRC}/${MY_SCRIPT} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MY_SCRIPT}.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/album
	${INSTALL_DATA} ${WRKSRC}/Docs/[Sa-z]* ${PREFIX}/share/doc/album
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/album/Pics
	${INSTALL_DATA} ${WRKSRC}/Docs/Pics/* ${PREFIX}/share/doc/album/Pics

.include "../../mk/bsd.pkg.mk"
