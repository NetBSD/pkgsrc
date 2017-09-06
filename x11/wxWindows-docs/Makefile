# $NetBSD: Makefile,v 1.12 2017/09/06 10:40:35 wiz Exp $

DISTNAME=		wxHTML22
PKGNAME=		wxWindows-docs-2.2
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		ftp://wesley.informatik.uni-freiburg.de/pub/linux/wxxt/docs/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.freiburg.linux.de/~wxxt/docs.html
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
