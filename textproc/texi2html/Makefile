# $NetBSD: Makefile,v 1.5 1998/08/20 15:17:29 tsarna Exp $
#

DISTNAME=		texi2html
PKGNAME=		texi2html-1.52
CATEGORIES=		textproc
MASTER_SITES=		http://wwwcn1.cern.ch/dci/texi2html/
EXTRACT_SUFX=		.shar.Z

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://wwwcn1.cern.ch/dci/texi2html/

USE_PERL5=		YES

EXTRACT_CMD=		${GZCAT}
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	|sh

NO_WRKSUBDIR=		yes
NO_CONFIGURE=		yes

do-build:
	cd ${WRKSRC}; \
		${SED} -e s@/usr/local/bin/perl@${PREFIX}/bin/perl@ texi2html >texi2html.new; \
		${SED} -e 1,/__END__/d texi2html >texi2html.1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/texi2html.new ${PREFIX}/bin/texi2html
	${INSTALL_DATA} ${WRKSRC}/texi2html.1 ${PREFIX}/man/man1/
	${INSTALL_DATA_DIR} ${PREFIX}/share/texi2html
	${INSTALL_DATA} ${WRKSRC}/invisible.xbm ${PREFIX}/share/texi2html

.include "../../mk/bsd.pkg.mk"
