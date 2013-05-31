# $NetBSD: Makefile,v 1.16 2013/05/31 12:42:30 wiz Exp $
#

DISTNAME=	album
ALBUMREV=	3.07
PKGNAME=	${DISTNAME}-${ALBUMREV}
PKGREVISION=	7
CATEGORIES=	www
MASTER_SITES=	http://marginalhacks.com/bin/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://marginalhacks.com/Hacks/album/
COMMENT=	Generate HTML albums of images

DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	jhead>=2.0:../../graphics/jhead
DEPENDS+=	ffmpeg-[0-9]*:../../multimedia/ffmpeg

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MY_SCRIPT=	album

USE_TOOLS+=	perl:run
REPLACE_PERL=	${MY_SCRIPT}
NO_BUILD=	YES

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/album/Pics

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${MY_SCRIPT} ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MY_SCRIPT}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/Docs/[Sa-z]* ${DESTDIR}${PREFIX}/share/doc/album
	${INSTALL_DATA} ${WRKSRC}/Docs/Pics/* ${DESTDIR}${PREFIX}/share/doc/album/Pics

.include "../../mk/bsd.pkg.mk"
