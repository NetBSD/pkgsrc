# $NetBSD: Makefile,v 1.1.1.1 2002/06/15 09:21:43 shell Exp $

DISTNAME=	dic
PKGNAME=	stardic-1.31
CATEGORIES=	textproc
MASTER_SITES=	http://download.linuxbyte.net/Chinese/dictionary/

MAINTAINER=	rxg@netbsd.org
COMMENT=	English-Chinese dictionary

DIST_SUBDIR=	${PKGNAME}

MAKEFILE=	makefile

post-patch:
	${MV} ${WRKSRC}/hzfont/fonts.dir ${WRKSRC}/hzfont/fonts.dir.orig
	${ECHO} '3' > ${WRKSRC}/hzfont/fonts.dir
	${ECHO} 'hz16.pcf.gz hz16' >> ${WRKSRC}/hzfont/fonts.dir
	${ECHO} 'hz16ft.pcf.gz hz16ft' >> ${WRKSRC}/hzfont/fonts.dir
	${ECHO} 'yb10x20.pcf.gz yb10x20' >> ${WRKSRC}/hzfont/fonts.dir

.include "../../mk/motif.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
