# $NetBSD: Makefile,v 1.9 2000/04/22 02:05:11 dmcmahill Exp $

DISTNAME=	ted-2.8.src
PKGNAME=	ted-2.8
WRKSRC=		${WRKDIR}/Ted-2.8
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/	\
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nllgg.nl/Ted/

DEPENDS+=	libungif-*:../../graphics/libungif
DEPENDS+=       jpeg-6b:../../graphics/jpeg
DEPENDS+=	png>=1.0.6:../../graphics/png
DEPENDS+=       tiff-*:../../graphics/tiff
DEPENDS+=       xpm-3.4k:../../graphics/xpm

USE_MOTIF=	YES
USE_X11=	YES

AFMDIR=		${PREFIX}/share/Ted/afm
INDDIR=		${PREFIX}/share/Ted/ind
INFODIR=	${PREFIX}/share/doc/Ted

MAKE_ENV+=	DEF_PKGDIR='-DPKGDIR=\"${PREFIX}\"' \
		DEF_AFMDIR='-DAFMDIR=\"${AFMDIR}\"' \
		DEF_INDDIR='-DINDDIR=\"${INDDIR}\"' \
		DEF_INFODIR='-DINFODIR=\"${INFODIR}\"'

ALL_TARGET=	compile

post-extract:
	@cd ${WRKSRC} ; ${GTAR} xf tedPackage/TedBindist.tar

post-patch:
	@cd ${WRKSRC}/info ; \
	${SED}	-e "s!Ted.afmDirectory:.*!Ted.afmDirectory:${AFMDIR}!g" \
		-e "s!Ted.spellToolSystemDicts:.*!Ted.spellToolSystemDicts:${INDDIR}!g" \
		-e "s!Ted.documentFileName:.*!Ted.documentFileName:${INFODIR}/TedDocument.rtf!g" \
		Ted.ad.sample > Ted

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Ted/Ted ${PREFIX}/bin/Ted
	${INSTALL_DATA_DIR} ${AFMDIR}
	${INSTALL_DATA} \
		${WRKSRC}/afm/Courier-Bold.afm \
		${WRKSRC}/afm/Courier-BoldOblique.afm \
		${WRKSRC}/afm/Courier-Oblique.afm \
		${WRKSRC}/afm/Courier.afm \
		${WRKSRC}/afm/Helvetica-Bold.afm \
		${WRKSRC}/afm/Helvetica-BoldOblique.afm \
		${WRKSRC}/afm/Helvetica-Oblique.afm \
		${WRKSRC}/afm/Helvetica.afm \
		${WRKSRC}/afm/Symbol.afm \
		${WRKSRC}/afm/Times-Bold.afm \
		${WRKSRC}/afm/Times-BoldItalic.afm \
		${WRKSRC}/afm/Times-Italic.afm \
		${WRKSRC}/afm/Times-Roman.afm \
		${AFMDIR}
	${INSTALL_DATA_DIR} ${INDDIR}
	${INSTALL_DATA} ${FILESDIR}/README.ind ${INDDIR}
	${INSTALL_DATA_DIR} ${INFODIR}
	${INSTALL_DATA} ${WRKSRC}/info/TedDocument.rtf ${INFODIR}
	${INSTALL_DATA}	${WRKSRC}/info/Ted ${PREFIX}/lib/X11/app-defaults \

.include "../../mk/bsd.pkg.mk"
