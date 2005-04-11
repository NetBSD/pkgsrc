# $NetBSD: Makefile,v 1.18 2005/04/11 21:48:02 tv Exp $
#

DISTNAME=	tidy_src_040811
PKGNAME=	tidy-20040811
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://tidy.sourceforge.net/src/ \
		http://tidy.sourceforge.net/docs/ \
		http://tidy.sourceforge.net/src/old/
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} tidy_docs_040810${EXTRACT_SUFX}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://tidy.sourceforge.net/
COMMENT=	Fixes and tidies up HTML files

WRKSRC=		${WRKDIR}/tidy
NO_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
BUILD_DIRS=	${WRKSRC}/build/gmake

OPSYSVARS+=	MAKEFLAGS
MAKEFLAGS.Darwin+=	RANLIB=ranlib

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
