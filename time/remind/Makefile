# $NetBSD: Makefile,v 1.6 2005/01/25 04:23:05 tv Exp $
#

DISTNAME=	remind-03.00.22
PKGNAME=	${DISTNAME:C/0([0-9])/\1/g}
PKGREVISION=	1
CATEGORIES=	time
MASTER_SITES=	http://www.roaringpenguin.com/penguin/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.roaringpenguin.com/penguin/open_source_remind.php
COMMENT=	Calendar/alarm program with interpreted input language

GNU_CONFIGURE=	yes

# We don't want to require tcl just for one script.
post-build:
	@${SED} -e 's,@TCLSH@,tclsh8.0,' \
		< ${WRKSRC}/scripts/cm2rem.tcl \
		> ${WRKSRC}/scripts/cm2rem
	@${MV} ${WRKSRC}/man/cm2rem.1 ${WRKSRC}/man/cm2rem.1.bak
	@${SED} -e 's,@TCLSH@,tclsh8.0,' \
		< ${WRKSRC}/man/cm2rem.1.bak \
		> ${WRKSRC}/man/cm2rem.1

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/remind
	(cd ${WRKSRC}; \
		${INSTALL_DATA} examples/defs.rem \
			${PREFIX}/share/examples/remind; \
		${INSTALL_DATA} examples/remind.vim \
			${PREFIX}/share/examples/remind; \
		${INSTALL_DATA} scripts/remind-all.csh \
			${PREFIX}/share/examples/remind; \
		${INSTALL_DATA} scripts/remind-all.sh \
			${PREFIX}/share/examples/remind)
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/remind
	(cd ${WRKSRC}; \
		${INSTALL_DATA} docs/README.UNIX \
			${PREFIX}/share/doc/remind; \
		${INSTALL_DATA} docs/WHATSNEW.30 \
			${PREFIX}/share/doc/remind; \
		${INSTALL_DATA} COPYRIGHT \
			${PREFIX}/share/doc/remind)

.include "../../mk/bsd.pkg.mk"
