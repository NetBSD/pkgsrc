# $NetBSD: Makefile,v 1.27 2019/08/11 13:24:13 wiz Exp $

DISTNAME=	remind-03.01.15
PKGNAME=	${DISTNAME:C/0([0-9])/\1/g}
PKGREVISION=	3
CATEGORIES=	time
MASTER_SITES=	http://www.roaringpenguin.com/files/download/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.roaringpenguin.com/products/remind
COMMENT=	Calendar/alarm program with interpreted input language
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl:run
USE_FEATURES=	glob

REPLACE_PERL=	www/rem2html

TEST_TARGET=	test

# We don't want to require tcl just for one script.
post-build:
	${SED} -e 's,@TCLSH@,tclsh8.4,' \
		< ${WRKSRC}/scripts/cm2rem.tcl \
		> ${WRKSRC}/scripts/cm2rem
	${MV} ${WRKSRC}/man/cm2rem.1 ${WRKSRC}/man/cm2rem.1.bak
	${SED} -e 's,@TCLSH@,tclsh8.4,' \
		< ${WRKSRC}/man/cm2rem.1.bak \
		> ${WRKSRC}/man/cm2rem.1

INSTALLATION_DIRS=	share/examples/remind share/doc/remind

post-install:
	cd ${WRKSRC}; \
		${INSTALL_DATA} examples/defs.rem \
			${DESTDIR}${PREFIX}/share/examples/remind; \
		${INSTALL_DATA} examples/remind.vim \
			${DESTDIR}${PREFIX}/share/examples/remind; \
	cd ${WRKSRC}; \
		${INSTALL_DATA} docs/README.UNIX \
			${DESTDIR}${PREFIX}/share/doc/remind; \
		${INSTALL_DATA} docs/WHATSNEW \
			${DESTDIR}${PREFIX}/share/doc/remind; \
		${INSTALL_DATA} COPYRIGHT \
			${DESTDIR}${PREFIX}/share/doc/remind
	${INSTALL_SCRIPT} ${WRKSRC}/www/rem2html \
		${DESTDIR}${PREFIX}/bin/rem2html

.include "../../mk/bsd.pkg.mk"
