# $NetBSD: Makefile,v 1.12 2003/10/28 12:33:48 cube Exp $
#

DISTNAME=	tidy_src_031002
PKGNAME=	tidy-20031002
WRKSRC=		${WRKDIR}/tidy
CATEGORIES=	www
MASTER_SITES=	http://tidy.sourceforge.net/src/ \
		http://tidy.sourceforge.net/docs/ \
		http://tidy.sourceforge.net/src/old/
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} tidy_docs_030610${EXTRACT_SUFX}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tidy.sourceforge.net/
COMMENT=	Fixes and tidies up HTML files

USE_BUILDLINK2=	yes
NO_CONFIGURE=	yes
USE_GMAKE=	yes
BUILD_DIRS=	${WRKSRC}/build/gmake

HTML_DOCFILES=	Overview.html doxygen.cfg grid.gif quickref.html tidy.css	\
		faq.html license.html pending.html release-notes.html tidy.gif
HTML_DOCDIR=	${PREFIX}/share/doc/html/tidy

post-install:
	${INSTALL_DATA_DIR} ${HTML_DOCDIR}
	for doc in ${HTML_DOCFILES}; do						\
	    ${INSTALL_DATA} ${WRKSRC}/htmldoc/$$doc ${HTML_DOCDIR} ;	\
	done
	${INSTALL_DATA_DIR} ${HTML_DOCDIR}/api
	for apifile in ${WRKSRC}/htmldoc/api/* ; do				\
	    ${INSTALL_DATA} $$apifile ${HTML_DOCDIR}/api ;			\
	done

.include "../../mk/bsd.pkg.mk"
