# $NetBSD: Makefile,v 1.2 2000/03/28 17:22:19 tron Exp $
# FreeBSD Id: ports/www/tidy/Makefile,v 1.15 2000/02/16 00:08:36 mharo Exp

DISTNAME=	tidy13jan00
PKGNAME=	tidy-20000113
CATEGORIES=	www
MASTER_SITES=	http://www.w3.org/People/Raggett/
EXTRACT_SUFX=	.tgz

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.w3c.org/People/Raggett/tidy/

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
