# $NetBSD: Makefile,v 1.11 2003/07/17 22:56:05 grant Exp $
#

DISTNAME=	tidy_src_021108
PKGNAME=	tidy-20021108
WRKSRC=		${WRKDIR}/tidy
CATEGORIES=	www
MASTER_SITES=	http://tidy.sourceforge.net/src/ \
		http://tidy.sourceforge.net/docs/ \
		http://tidy.sourceforge.net/src/old/
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} tidy_docs_021021${EXTRACT_SUFX}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tidy.sourceforge.net/
COMMENT=	Fixes and tidies up HTML files

ALL_TARGET=	tidy
CFLAGS+=	-DPRESERVE_FILE_TIMES=0

DOCFILES=	htmldoc/Overview.html htmldoc/tidy.gif \
		htmldoc/release-notes.html htmldoc/grid.gif

USE_GMAKE=	yes

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/tidy ${PREFIX}/bin/tidy
	@${INSTALL_MAN}	${WRKSRC}/man_page.txt	${PREFIX}/man/man1/tidy.1
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tidy
.for docfile in ${DOCFILES}
	@${INSTALL_DATA} ${WRKSRC}/${docfile} ${PREFIX}/share/doc/tidy
.endfor

.include "../../mk/bsd.pkg.mk"
