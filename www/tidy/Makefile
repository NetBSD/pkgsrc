# $NetBSD: Makefile,v 1.20 2005/10/04 18:00:49 wiz Exp $
#

DISTNAME=	tidy_src_050921
PKGNAME=	tidy-20050921
CATEGORIES=	www
MASTER_SITES=	http://tidy.sourceforge.net/src/ \
		http://tidy.sourceforge.net/src/old/
SITES_tidy_docs_050705.tgz=	http://tidy.sourceforge.net/docs/
EXTRACT_SUFX=	.tgz
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} tidy_docs_050705${EXTRACT_SUFX}

MAINTAINER=	asmodai@in-nomine.org
HOMEPAGE=	http://tidy.sourceforge.net/
COMMENT=	Fixes and tidies up HTML files

BUILD_DEPENDS=	libxslt>=1.1.0:../../textproc/libxslt

WRKSRC=		${WRKDIR}/tidy
NO_CONFIGURE=	yes
USE_TOOLS+=	gmake
BUILD_DIRS=	${WRKSRC}/build/gmake

OPSYSVARS+=	MAKEFLAGS
MAKEFLAGS.Darwin+=	RANLIB=ranlib

HTML_DOCFILES=	Overview.html doxygen.cfg grid.gif quickref.html tidy.css \
		faq.html license.html pending.html release-notes.html tidy.gif
HTML_DOCDIR=	${PREFIX}/share/doc/html/tidy

post-build:
	cd ${BUILD_DIRS} && ${GMAKE} doc

post-install:
	${INSTALL_DATA_DIR} ${HTML_DOCDIR}
	for doc in ${HTML_DOCFILES}; do					\
	    ${INSTALL_DATA} ${WRKSRC}/htmldoc/$$doc ${HTML_DOCDIR} ;	\
	done
	${INSTALL_DATA_DIR} ${HTML_DOCDIR}/api
	for apifile in ${WRKSRC}/htmldoc/api/* ; do			\
	    ${INSTALL_DATA} $$apifile ${HTML_DOCDIR}/api ;		\
	done

.include "../../mk/bsd.pkg.mk"
