# $NetBSD: Makefile,v 1.7 2006/01/24 07:32:41 wiz Exp $
#

DISTNAME=	album
ALBUMREV=	3.07
PKGNAME=	${DISTNAME}-${ALBUMREV}
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://marginalhacks.com/bin/

MAINTAINER=	augustss@NetBSD.org
HOMEPAGE=	http://marginalhacks.com/Hacks/album/
COMMENT=	Generate HTML albums of images

DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	jhead-[2-9]*:../../graphics/jhead
DEPENDS+=	ffmpeg-[0-9]*:../../multimedia/ffmpeg

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MY_SCRIPT=	album

USE_TOOLS+=	perl:run
REPLACE_PERL=	${MY_SCRIPT}

NO_CONFIGURE=	YES
NO_BUILD=	YES

INSTALLATION_DIRS=	bin man/man1

do-install:	replace-interpreter
	${INSTALL_SCRIPT} ${WRKSRC}/${MY_SCRIPT} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MY_SCRIPT}.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/album
	${INSTALL_DATA} ${WRKSRC}/Docs/[Sa-z]* ${PREFIX}/share/doc/album
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/album/Pics
	${INSTALL_DATA} ${WRKSRC}/Docs/Pics/* ${PREFIX}/share/doc/album/Pics

.include "../../mk/bsd.pkg.mk"
