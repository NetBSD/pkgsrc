# $NetBSD: Makefile,v 1.14 2001/05/24 03:04:05 jlam Exp $

DISTNAME=	mod_dtcl-0.10.1
PKGNAME=	ap-dtcl-0.10.1
WRKSRC=		${WRKDIR}/mod_dtcl
CATEGORIES=	www
MASTER_SITES=	http://tcl.apache.org/mod_dtcl/download/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://tcl.apache.org/
COMMENT=	Simple, fast Tcl server side scripting for apache

DEPENDS+=	apache{,6}-1.3.*:../../www/apache
DEPENDS+=	tcl>=8.3.2nb2:../../lang/tcl

TCLSH=		${LOCALBASE}/bin/tclsh
CPPFLAGS+=	-I${PREFIX}/include/httpd

MAKE_ENV+=	TCLSH="${TCLSH}"
MAKE_ENV+=	INCLUDES="${CPPFLAGS}"

APACHEMODDIR=	${PREFIX}/lib/httpd
HTMLDIR=	${PREFIX}/share/doc/html/mod_dtcl
EGDIR=		${PREFIX}/share/examples/mod_dtcl

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} builddtcl.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/mod_dtcl.so ${APACHEMODDIR}
	${INSTALL_DATA_DIR} ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.gif ${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${HTMLDIR}
	${INSTALL_DATA_DIR} ${EGDIR}/tests
	cd ${WRKSRC}; ${INSTALL_DATA} tests/README ${EGDIR}/tests
	cd ${WRKSRC}; ${INSTALL_DATA} tests/dtcl-test.ttml ${EGDIR}/tests
	cd ${WRKSRC}; ${INSTALL_DATA} tests/dtcl.test ${EGDIR}/tests
	cd ${WRKSRC}; ${INSTALL_DATA} contrib/*.ttml ${EGDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} contrib/*.tcl ${EGDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} docs/examples.ttml ${EGDIR}

.include "../../mk/bsd.pkg.mk"
