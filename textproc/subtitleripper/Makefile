# $NetBSD: Makefile,v 1.20 2008/09/06 09:19:02 wiz Exp $
#

DISTNAME=	subtitleripper-0.3-4
PKGNAME=	subtitleripper-0.3.4
CATEGORIES=	textproc graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=subtitleripper/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/subtitleripper/
COMMENT=	Subtitle ripping program

DEPENDS+=	gocr-[0-9]*:../../graphics/gocr

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/subtitleripper
INSTALLATION_DIRS=	bin

CONFLICTS+=	subtitleripper-0.3-[0-9]*

do-install:
	${SED} -e "s,@PREFIX@,${PREFIX}," <${WRKSRC}/pgm2txt >${WRKDIR}/pgm2txt
	${INSTALL_SCRIPT} ${WRKDIR}/pgm2txt ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/subtitle2pgm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/srttool ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/subtitle2vobsub ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/subtitleripper
	cd ${WRKSRC}; ${INSTALL_DATA} README README.gocr README.srttool \
		README.subtitle2pgm README.vobsub \
		${PREFIX}/share/doc/subtitleripper
	${INSTALL_DATA_DIR} ${PREFIX}/libdata/subtitleripper
	cd ${WRKSRC}; ${INSTALL_DATA} gocrfilter_en.sed \
		gocrfilter_fr.sed gocrfilter_nl.sed gocrfilter_none.sed \
		${PREFIX}/libdata/subtitleripper

.include "../../graphics/netpbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
