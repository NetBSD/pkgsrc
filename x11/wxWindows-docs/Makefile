# $NetBSD: Makefile,v 1.4 2003/07/17 22:56:50 grant Exp $

DISTNAME=		wxHTML22
PKGNAME=		wxWindows-docs-2.2
WRKSRC=			${WRKDIR}/wxHTML
CATEGORIES=		x11
MASTER_SITES=		ftp://wesley.informatik.uni-freiburg.de/pub/linux/wxxt/docs/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jlam@NetBSD.org
HOMEPAGE=		http://www.freiburg.linux.de/~wxxt/docs.html
COMMENT=		HTML documentation for wxWindows

NO_CONFIGURE=		# defined
NO_BUILD=		# defined

HTMLDIR=		${PREFIX}/share/doc/html/wx

do-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${HTMLDIR}
	${LN} -sf wxwin.htm ${HTMLDIR}/index.html

.include "../../mk/bsd.pkg.mk"
