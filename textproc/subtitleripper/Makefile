# $NetBSD: Makefile,v 1.3 2003/07/21 17:27:53 martti Exp $
#

DISTNAME=	subtitleripper-0.3-1
CATEGORIES=	textproc graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=subtitleripper/}
EXTRACT_SUFX=	.tgz
WRKSRC=		${WRKDIR}/subtitleripper

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://sourceforge.net/projects/subtitleripper/
COMMENT=	Sub title ripping program

DEPENDS+=	gocr-[0-9]*:../../textproc/gocr

USE_BUILDLINK2=		yes
USE_GMAKE=		yes

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pgm2txt ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/subtitle2pgm ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/srttool ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/subtitle2vobsub ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${LOCALBASE}/share/doc/subtitleripper
	cd ${WRKSRC}; ${INSTALL_DATA} README README.gocr README.srttool \
		README.subtitle2pgm README.vobsub gocrfilter_en.sed \
		gocrfilter_fr.sed gocrfilter_nl.sed  gocrfilter_none.sed \
		${LOCALBASE}/share/doc/subtitleripper

.include "../../graphics/netpbm/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
