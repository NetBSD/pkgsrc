# $NetBSD: Makefile,v 1.7 2000/08/27 02:46:07 jlam Exp $
#

DISTNAME=		texi2html
PKGNAME=		texi2html-1.52
CATEGORIES=		textproc
MASTER_SITES=		http://wwwcn1.cern.ch/dci/texi2html/
EXTRACT_SUFX=		.shar.Z

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://wwwcn1.cern.ch/dci/texi2html/

USE_PERL5=		# defined

EXTRACT_CMD=		${GZCAT} ${DOWNLOADED_DISTFILE} | ${SH}

NO_WRKSUBDIR=		# defined
NO_CONFIGURE=		# defined

do-build:
	cd ${WRKSRC}; \
		${SED} -e s@/usr/local/bin/perl@${PERL5}@ \
			<texi2html >texi2html.new; \
		${SED} -e 1,/__END__/d <texi2html >texi2html.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/texi2html.new ${PREFIX}/bin/texi2html
	${INSTALL_DATA} ${WRKSRC}/texi2html.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/texi2html
	${INSTALL_DATA} ${WRKSRC}/invisible.xbm ${PREFIX}/share/texi2html

.include "../../mk/bsd.pkg.mk"
