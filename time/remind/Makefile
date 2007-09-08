# $NetBSD: Makefile,v 1.11 2007/09/08 21:58:01 jlam Exp $
#

DISTNAME=	remind-03.00.24
PKGNAME=	${DISTNAME:C/0([0-9])/\1/g}
CATEGORIES=	time
MASTER_SITES=	http://www.roaringpenguin.com/penguin/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.roaringpenguin.com/penguin/openSourceProducts/remind
COMMENT=	Calendar/alarm program with interpreted input language

GNU_CONFIGURE=	yes
USE_TOOLS+=	perl:run
USE_FEATURES=	glob

REPLACE_PERL=	www/rem2html

# We don't want to require tcl just for one script.
post-build:
	${SED} -e 's,@TCLSH@,tclsh8.0,' \
		< ${WRKSRC}/scripts/cm2rem.tcl \
		> ${WRKSRC}/scripts/cm2rem
	${MV} ${WRKSRC}/man/cm2rem.1 ${WRKSRC}/man/cm2rem.1.bak
	${SED} -e 's,@TCLSH@,tclsh8.0,' \
		< ${WRKSRC}/man/cm2rem.1.bak \
		> ${WRKSRC}/man/cm2rem.1

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/remind
	cd ${WRKSRC}; \
		${INSTALL_DATA} examples/defs.rem \
			${PREFIX}/share/examples/remind; \
		${INSTALL_DATA} examples/remind.vim \
			${PREFIX}/share/examples/remind; \
		${INSTALL_DATA} scripts/remind-all.csh \
			${PREFIX}/share/examples/remind; \
		${INSTALL_DATA} scripts/remind-all.sh \
			${PREFIX}/share/examples/remind
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/remind
	cd ${WRKSRC}; \
		${INSTALL_DATA} docs/README.UNIX \
			${PREFIX}/share/doc/remind; \
		${INSTALL_DATA} docs/WHATSNEW.30 \
			${PREFIX}/share/doc/remind; \
		${INSTALL_DATA} COPYRIGHT \
			${PREFIX}/share/doc/remind
	${INSTALL_SCRIPT} ${WRKSRC}/www/rem2html \
		${PREFIX}/bin/rem2html

.include "../../mk/bsd.pkg.mk"
