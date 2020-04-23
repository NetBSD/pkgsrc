# $NetBSD: Makefile,v 1.28 2020/04/23 17:04:10 nia Exp $

DISTNAME=	album-4.15
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	http://marginalhacks.com/bin/album.versions/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://marginalhacks.com/Hacks/album/
COMMENT=	Generate HTML albums of images
#LICENSE=	http://marginalhacks.com/License/

DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick
DEPENDS+=	jhead>=2.0:../../graphics/jhead
DEPENDS+=	ffmpeg4-[0-9]*:../../multimedia/ffmpeg4

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

MY_SCRIPT=	album

USE_TOOLS+=	perl:run
REPLACE_PERL=	${MY_SCRIPT}
NO_BUILD=	YES

AUTO_MKDIRS=		yes

SUBST_CLASSES+=		prefix
SUBST_MESSAGE.prefix=	Adjust Install Path to ${PREFIX}
SUBST_STAGE.prefix=	pre-configure
SUBST_FILES.prefix=	album
SUBST_VARS.prefix=	PREFIX

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${MY_SCRIPT} ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${MY_SCRIPT}.1  ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/Docs/Section*  ${DESTDIR}${PREFIX}/share/doc/album
	${INSTALL_DATA} ${WRKSRC}/Docs/txt*      ${DESTDIR}${PREFIX}/share/doc/album
	${INSTALL_DATA} ${WRKSRC}/Docs/Pics/*    ${DESTDIR}${PREFIX}/share/doc/album/Pics
	for f in Short.html conf conf.bak flag.png index.html make_docs ; do \
		${INSTALL_DATA} ${WRKSRC}/Docs/$${f}  ${DESTDIR}${PREFIX}/share/doc/album ;\
	done
	for d in de es fr hu it nl ru ; do \
	${INSTALL_DATA} ${WRKSRC}/Docs/$${d}/* ${DESTDIR}${PREFIX}/share/doc/album/$${d} ;\
	done

.include "../../mk/bsd.pkg.mk"
