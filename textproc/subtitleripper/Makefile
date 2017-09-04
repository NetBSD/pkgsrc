# $NetBSD: Makefile,v 1.31 2017/09/04 18:08:29 wiz Exp $
#

DISTNAME=	subtitleripper-0.3-4
PKGNAME=	subtitleripper-0.3.4
PKGREVISION=	8
CATEGORIES=	textproc graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=subtitleripper/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/subtitleripper/
COMMENT=	Subtitle ripping program

DEPENDS+=	gocr-[0-9]*:../../graphics/gocr

USE_TOOLS+=		gmake
WRKSRC=			${WRKDIR}/subtitleripper
CPPFLAGS+=		-I${BUILDLINK_PREFIX.netpbm}/include/netpbm
INSTALLATION_DIRS=	bin libdata/subtitleripper share/doc/subtitleripper

CONFLICTS+=	subtitleripper-0.3-[0-9]*

do-install:
	${SED} -e "s,@PREFIX@,${PREFIX}," <${WRKSRC}/pgm2txt >${WRKDIR}/pgm2txt
	${INSTALL_SCRIPT} ${WRKDIR}/pgm2txt ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/subtitle2pgm ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/srttool ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/subtitle2vobsub ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}; ${INSTALL_DATA} README README.gocr README.srttool \
		README.subtitle2pgm README.vobsub \
		${DESTDIR}${PREFIX}/share/doc/subtitleripper
	cd ${WRKSRC}; ${INSTALL_DATA} gocrfilter_en.sed \
		gocrfilter_fr.sed gocrfilter_nl.sed gocrfilter_none.sed \
		${DESTDIR}${PREFIX}/libdata/subtitleripper

.include "../../graphics/netpbm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
