# $NetBSD: Makefile,v 1.1.1.1 2000/12/13 17:41:20 jlam Exp $

DISTNAME=		wxHTML22
PKGNAME=		wxWindows-docs-2.2
WRKSRC=			${WRKDIR}/wxHTML
CATEGORIES=		x11
MASTER_SITES=		ftp://wesley.informatik.uni-freiburg.de/pub/linux/wxxt/docs/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.freiburg.linux.de/~wxxt/docs.html

NO_CONFIGURE=		# defined
NO_BUILD=		# defined

HTMLDIR=		${PREFIX}/share/doc/html/wx/

do-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${HTMLDIR}
	${LN} -sf wxwin.htm ${HTMLDIR}/index.html

.include "../../mk/bsd.pkg.mk"
