# $NetBSD: Makefile,v 1.7 2002/03/08 11:55:43 wiz Exp $
#

DISTNAME=	tidy_src_020307
PKGNAME=	tidy-20020307
WRKSRC=		${WRKDIR}/tidy
CATEGORIES=	www
MASTER_SITES=	http://tidy.sourceforge.net/src/ \
		http://tidy.sourceforge.net/docs/ \
		http://tidy.sourceforge.net/src/old/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.w3c.org/People/Raggett/tidy/
COMMENT=	Fixes and tidies up HTML files

DISTFILES=	${DISTNAME}${EXTRACT_SUFX} tidy_docs_000804${EXTRACT_SUFX}
ALL_TARGET=	tidy
CFLAGS+=	-DPRESERVE_FILE_TIMES=0

DOCFILES=	htmldoc/Overview.html htmldoc/tidy.gif \
		htmldoc/release-notes.html htmldoc/grid.gif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/tidy ${PREFIX}/bin/tidy
	@${INSTALL_MAN}	${WRKSRC}/man_page.txt	${PREFIX}/man/man1/tidy.1
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tidy
.for docfile in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${PREFIX}/share/doc/tidy
.endfor

.include "../../mk/bsd.pkg.mk"
