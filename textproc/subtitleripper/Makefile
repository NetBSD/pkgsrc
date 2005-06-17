# $NetBSD: Makefile,v 1.12 2005/06/17 04:49:49 jlam Exp $
#

DISTNAME=	subtitleripper-0.3-1
PKGREVISION=	2
CATEGORIES=	textproc graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=subtitleripper/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/subtitleripper/
COMMENT=	Sub title ripping program

DEPENDS+=	gocr-[0-9]*:../../textproc/gocr

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/subtitleripper
INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pgm2txt ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/subtitle2pgm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/srttool ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/subtitle2vobsub ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/subtitleripper
	cd ${WRKSRC}; ${INSTALL_DATA} README README.gocr README.srttool \
		README.subtitle2pgm README.vobsub gocrfilter_en.sed \
		gocrfilter_fr.sed gocrfilter_nl.sed  gocrfilter_none.sed \
		${PREFIX}/share/doc/subtitleripper

.include "../../graphics/netpbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
