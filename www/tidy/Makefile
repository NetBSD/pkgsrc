# $NetBSD: Makefile,v 1.4 2001/02/17 17:22:42 wiz Exp $
# FreeBSD Id: ports/www/tidy/Makefile,v 1.15 2000/02/16 00:08:36 mharo Exp

DISTNAME=	tidy4aug00
PKGNAME=	tidy-20000804
CATEGORIES=	www
MASTER_SITES=	http://www.w3.org/People/Raggett/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.w3c.org/People/Raggett/tidy/
COMMENT=	Fixes and tidies up HTML files

ALL_TARGET=	tidy

DOCFILES=	Overview.html tidy.gif release-notes.html grid.gif

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/tidy ${PREFIX}/bin/tidy
	@${INSTALL_MAN}	${WRKSRC}/man_page.txt	${PREFIX}/man/man1/tidy.1
	@${ECHO_MSG} "===>   Installing documentation for ${PKGNAME}"
	@${MKDIR} ${PREFIX}/share/doc/tidy
.for docfile in ${DOCFILES}
	@${INSTALL_MAN} ${WRKSRC}/${docfile} ${PREFIX}/share/doc/tidy
.endfor

.include "../../mk/bsd.pkg.mk"
