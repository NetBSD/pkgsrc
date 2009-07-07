# $NetBSD: Makefile,v 1.22 2009/07/07 20:49:20 joerg Exp $
#

DISTNAME=		RTF-1.10
PKGNAME=		rtf-tools-1.10
PKGREVISION=		2
CATEGORIES=		textproc
MASTER_SITES=		http://www.snake.net/software/RTF/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		RTF to troff/groff/text converter

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}/rtf
INSTALL_TARGET=		install install.man
INSTALLATION_DIRS=	bin ${PKGMANDIR}/manl lib/rtf-tools

SUBST_CLASSES+=		rtf
SUBST_STAGE.rtf=	pre-configure
SUBST_MESSAGE.rtf=	Fixing absolute paths in Makefiles.
SUBST_FILES.rtf=	Makefile */Makefile
SUBST_SED.rtf+=		-e 's|-DVARARGS|-DSTDARGS|g'
SUBST_SED.rtf+=		-e 's|/usr/local|${PREFIX}|g'
SUBST_SED.rtf+=		-e 's|/usr/man|${PREFIX}/man|'
SUBST_SED.rtf+=		-e 's|\(LOCALBINDIR =.*\)|\1/bin|'

do-install:
	${INSTALL_DATA} ${WRKSRC}/h/standard-names ${DESTDIR}${PREFIX}/lib/rtf-tools
	cd ${WRKSRC}/lib && ${INSTALL_DATA} ansi-gen ansi-sym \
		ansicpg1252-gen ansicpg1252-sym \
		mac-gen mac-sym pc-gen pc-sym pca-gen pca-sym \
		${DESTDIR}${PREFIX}/lib/rtf-tools
	${INSTALL_DATA} ${WRKSRC}/rtf2text/text-map ${DESTDIR}${PREFIX}/lib/rtf-tools
	cd ${WRKSRC}/rtf2troff && ${INSTALL_DATA} troff-map groff-map \
		xroff-map dwbtroff-map troff-man-map troff-me-map \
		troff-mm-map troff-ms-map ${DESTDIR}${PREFIX}/lib/rtf-tools
	${INSTALL_SCRIPT} ${WRKSRC}/util/rtfchkmap ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/util/rtfmaptortf ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rtf2null/rtf2null ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rtf2text/rtf2text ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rtf2troff/rtf2troff ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/rtf2troff/rtf2groff ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rtfdiag/rtfdiag ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rtfindent/rtfindent ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/rtfwc/rtfwc ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/rtf2troff.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/manl/rtf2troff.l

.include "../../devel/libts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
