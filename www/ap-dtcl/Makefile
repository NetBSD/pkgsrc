# $NetBSD: Makefile,v 1.13 2001/05/20 05:23:27 jonb Exp $

DISTNAME=	mod_dtcl-0.8.12
PKGNAME=	ap-dtcl-0.8.12
WRKSRC=		${WRKDIR}/mod_dtcl
CATEGORIES=	www
MASTER_SITES=	http://tcl.apache.org/mod_dtcl/download/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://tcl.apache.org/
COMMENT=	Simple, fast Tcl server side scripting for apache

DEPENDS+=	apache{,6}-1.3.*:../../www/apache
DEPENDS+=	tcl>=8.3.2:../../lang/tcl
# For "apxs":
BUILD_DEPENDS=	perl>=${PERL5_REQD}:../../lang/perl5

INCLUDES=	-I${PREFIX}/include/
LIBS=		-L${PREFIX}/lib -Wl,-R${PREFIX}/lib -ltcl83 -lm

do-build:
	cd ${WRKSRC} && ${PREFIX}/sbin/apxs -DDTCL_VERSION=\\\"`cat ${WRKSRC}/VERSION`\\\" ${INCLUDES} ${LIBS} -c mod_dtcl.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i mod_dtcl.so
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_dtcl
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${PREFIX}/share/doc/mod_dtcl
	${INSTALL_DATA} ${WRKSRC}/docs/*.gif ${PREFIX}/share/doc/mod_dtcl
	${INSTALL_DATA} ${WRKSRC}/docs/*.txt ${PREFIX}/share/doc/mod_dtcl
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mod_dtcl
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/mod_dtcl/tests
	${INSTALL_DATA} ${WRKSRC}/tests/README ${PREFIX}/share/examples/mod_dtcl/tests
	${INSTALL_DATA} ${WRKSRC}/tests/dtcl-test.ttml ${PREFIX}/share/examples/mod_dtcl/tests
	${INSTALL_DATA} ${WRKSRC}/tests/dtcl.test ${PREFIX}/share/examples/mod_dtcl/tests
	${INSTALL_DATA} ${WRKSRC}/contrib/*.ttml ${PREFIX}/share/examples/mod_dtcl
	${INSTALL_DATA} ${WRKSRC}/contrib/*.tcl ${PREFIX}/share/examples/mod_dtcl
	${INSTALL_DATA} ${WRKSRC}/docs/examples.ttml ${PREFIX}/share/examples/mod_dtcl

.include "../../mk/bsd.pkg.mk"
