# $NetBSD: Makefile,v 1.18 2005/06/17 03:50:37 jlam Exp $
#

DISTNAME=		RTF-1.10
PKGNAME=		rtf-tools-1.10
PKGREVISION=		2
CATEGORIES=		textproc
MASTER_SITES=		http://www.snake.net/software/RTF/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		RTF to troff/groff/text converter

WRKSRC=			${WRKDIR}/rtf
INSTALL_TARGET=		install install.man
INSTALLATION_DIRS=	bin man/manl

post-patch:
	for i in `${FIND} ${WRKSRC} -name Makefile -print`; do \
		${MV} $$i $$i.bak;\
		${SED} <$$i.bak >$$i \
			-e "s|-DVARARGS|-DSTDARGS|g" \
			-e "s|/usr/local|${PREFIX}|g" \
			-e "s|/usr/man|${PREFIX}/man|" \
			-e "s|\(LOCALBINDIR =.*\)|\1/bin|" ;\
	done

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/lib/rtf-tools
	${INSTALL_DATA} ${WRKSRC}/h/standard-names ${PREFIX}/lib/rtf-tools
	cd ${WRKSRC}/lib && ${INSTALL_DATA} ansi-gen ansi-sym \
		ansicpg1252-gen ansicpg1252-sym \
		mac-gen mac-sym pc-gen pc-sym pca-gen pca-sym \
		${PREFIX}/lib/rtf-tools
	${INSTALL_DATA} ${WRKSRC}/rtf2text/text-map ${PREFIX}/lib/rtf-tools
	cd ${WRKSRC}/rtf2troff && ${INSTALL_DATA} troff-map groff-map \
		xroff-map dwbtroff-map troff-man-map troff-me-map \
		troff-mm-map troff-ms-map ${PREFIX}/lib/rtf-tools
	${INSTALL_SCRIPT} ${WRKSRC}/util/rtfchkmap ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/util/rtfmaptortf ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rtf2null/rtf2null ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rtf2text/rtf2text ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rtf2troff/rtf2troff ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/rtf2troff/rtf2groff ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rtfdiag/rtfdiag ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rtfindent/rtfindent ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rtfwc/rtfwc ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/rtf2troff.man \
		${PREFIX}/man/manl/rtf2troff.l

.include "../../devel/libts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
