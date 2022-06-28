# $NetBSD: Makefile,v 1.32 2022/06/28 11:36:59 wiz Exp $

DISTNAME=	remind-03.02.00
PKGNAME=	${DISTNAME:C/0([0-9])/\1/g}
PKGREVISION=	3
CATEGORIES=	time
MASTER_SITES=	https://dianne.skoll.ca/projects/remind/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://dianne.skoll.ca/projects/remind/
COMMENT=	Calendar/alarm program with interpreted input language
LICENSE=	gnu-gpl-v2

EXTRACT_USING=	bsdtar
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
