# $NetBSD: Makefile,v 1.9 2006/04/12 21:54:35 rillig Exp $

DISTNAME=		wxHTML22
PKGNAME=		wxWindows-docs-2.2
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		ftp://wesley.informatik.uni-freiburg.de/pub/linux/wxxt/docs/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.freiburg.linux.de/~wxxt/docs.html
COMMENT=		HTML documentation for wxWindows

WRKSRC=			${WRKDIR}/wxHTML
NO_CONFIGURE=		yes
NO_BUILD=		yes

HTMLDIR=		${PREFIX}/share/doc/wx

do-install:
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${HTMLDIR}
	${LN} -sf wxwin.htm ${HTMLDIR}/index.html

.include "../../mk/bsd.pkg.mk"
