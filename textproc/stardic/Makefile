# $NetBSD: Makefile,v 1.5 2004/05/03 23:00:20 wiz Exp $

DISTNAME=	dic
PKGNAME=	stardic-1.31
CATEGORIES=	textproc
MASTER_SITES=	http://download.linuxbyte.net/Chinese/dictionary/

MAINTAINER=	rxg@NetBSD.org
COMMENT=	English-Chinese dictionary

DIST_SUBDIR=	${PKGNAME}

USE_BUILDLINK3=	# defined
USE_X11=	# defined
MAKEFILE=	makefile
USE_LANGUAGES=	c c++

post-patch:
	${CHMOD} u+w  ${WRKSRC}/hzfont
	${MV} ${WRKSRC}/hzfont/fonts.dir ${WRKSRC}/hzfont/fonts.dir.orig
	${ECHO} '3' > ${WRKSRC}/hzfont/fonts.dir
	${ECHO} 'hz16.pcf.gz hz16' >> ${WRKSRC}/hzfont/fonts.dir
	${ECHO} 'hz16ft.pcf.gz hz16ft' >> ${WRKSRC}/hzfont/fonts.dir
	${ECHO} 'yb10x20.pcf.gz yb10x20' >> ${WRKSRC}/hzfont/fonts.dir

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
