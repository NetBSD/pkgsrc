# $NetBSD: Makefile,v 1.1.1.1 2000/12/17 23:32:11 wiz Exp $
#

DISTNAME=	remind-03.00.21
PKGNAME=	${DISTNAME:C/0([0-9])/\1/g}
CATEGORIES=	time
MASTER_SITES=	http://www.roaringpenguin.com/

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.roaringpenguin.com/remind.html

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
		${INSTALL_DATA} -p examples/defs.rem \
			${PREFIX}/share/examples/remind; \
		${INSTALL_DATA} -p examples/remind.vim \
			${PREFIX}/share/examples/remind; \
		${INSTALL_DATA} -p scripts/remind-all.csh \
			${PREFIX}/share/examples/remind; \
		${INSTALL_DATA} -p scripts/remind-all.sh \
			${PREFIX}/share/examples/remind)
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/remind
	(cd ${WRKSRC}; \
		${INSTALL_DATA} -p docs/README.UNIX \
			${PREFIX}/share/doc/remind; \
		${INSTALL_DATA} -p docs/WHATSNEW.30 \
			${PREFIX}/share/doc/remind; \
		${INSTALL_DATA} -p COPYRIGHT \
			${PREFIX}/share/doc/remind)

.include "../../mk/bsd.pkg.mk"
