# $NetBSD: Makefile,v 1.28 2022/06/28 11:36:50 wiz Exp $
#

DISTNAME=		troffcvt-1.04
PKGREVISION=		11
CATEGORIES=		textproc
MASTER_SITES=		http://www.snake.net/software/troffcvt/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Troff/groff to RTF/HTML/TEXT converter

MAKE_JOBS_SAFE=		no

USE_TOOLS+=		perl:run

INSTALL_TARGET=		install install.man
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 lib/troffcvt

post-patch:
	for i in `${FIND} ${WRKSRC} -name Makefile -print`; do \
		${MV} $$i $$i.bak;\
		${SED} <$$i.bak >$$i \
			-e "s| -Dsun -DSVR4||" \
			-e "s| -lsocket -lnsl -lw||" \
			-e "s| -Xc||" \
			-e "s|/usr/include/sys/feature_tests.h||" \
			-e "s|/usr/tmp|/tmp|g" \
			-e "s|/usr/local|${PREFIX}|g" \
			-e "s|/usr/local/man|${PREFIX}/man|" ;\
	done

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/troffcvt/troffcvt ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tblcvt/tblcvt ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/post && ${INSTALL_PROGRAM} tc2null tc2html tc2rtf tc2text \
		${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/post && ${INSTALL_SCRIPT} troff2null tc2html-toc \
		troff2html troff2rtf unroff ${DESTDIR}${PREFIX}/bin
	cd ${WRKSRC}/troffcvt && ${INSTALL_DATA} actions actions-html \
		tc.man tc.man-html tc.me tc.me-html tc.mm tc.mm-html tc.ms \
		tc.ms-html tc.mdoc tc.mdoc-html ${DESTDIR}${PREFIX}/lib/troffcvt
	cd ${WRKSRC}/post && ${INSTALL_DATA} tcr-fonts html-fonts \
		html-specials rtf-fonts rtf-spec-ansi rtf-spec-mac \
		rtf-spec-pc rtf-spec-pca text-specials text-8-specials \
		${DESTDIR}${PREFIX}/lib/troffcvt
	${INSTALL_MAN} ${WRKSRC}/man/tblcvt.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tblcvt.1
	${INSTALL_MAN} ${WRKSRC}/man/unroff.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/unroff.1
	${INSTALL_MAN} ${WRKSRC}/man/troff2rtf.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/troff2rtf.1
	${INSTALL_MAN} ${WRKSRC}/man/tc2html-toc.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tc2html-toc.1
	${INSTALL_MAN} ${WRKSRC}/man/troff2html.man \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/troff2html.1
	${INSTALL_MAN} ${WRKSRC}/man/tc2html.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/tc2html.1
	${INSTALL_MAN} ${WRKSRC}/man/troffcvt.man ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/troffcvt.1

.include "../../devel/libmemmgr/buildlink3.mk"
.include "../../devel/libportlib/buildlink3.mk"
.include "../../devel/libts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
