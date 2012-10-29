# $NetBSD: Makefile,v 1.11 2012/10/29 05:06:56 asau Exp $

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

INSTALLATION_DIRS+=	share/doc/wx

do-install:
	${INSTALL_DATA} ${WRKSRC}/* ${DESTDIR}${HTMLDIR}
	${LN} -sf wxwin.htm ${DESTDIR}${HTMLDIR}/index.html

.include "../../mk/bsd.pkg.mk"
