# $NetBSD: Makefile,v 1.32 2012/10/28 06:30:04 asau Exp $

DISTNAME=	mod_dtcl-0.11.6
PKGNAME=	ap13-dtcl-0.11.2
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://tcl.apache.org/mod_dtcl/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tcl.apache.org/
COMMENT=	Simple, fast Tcl server side scripting for apache

CONFLICTS=	ap-dtcl-[0-9]*

WRKSRC=		${WRKDIR}/mod_dtcl

TCLSH=		${BUILDLINK_PREFIX.tcl}/bin/tclsh
CPPFLAGS+=	-I${BUILDLINK_PREFIX.apache}/include/httpd -DEAPI

MAKE_ENV+=	TCLSH=${TCLSH:Q}
MAKE_ENV+=	INCLUDES=${CPPFLAGS:M*:Q}

APACHE_MODULE=	yes
APACHEMODDIR=	${PREFIX}/lib/httpd
HTMLDIR=	${PREFIX}/share/doc/html/mod_dtcl
EGDIR=		${PREFIX}/share/examples/mod_dtcl

INSTALLATION_DIRS=	${APACHEMODDIR} ${HTMLDIR} ${EGDIR}/tests

.include "../../lang/tcl/buildlink3.mk"
.include "../../www/apache/buildlink3.mk"

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SH} builddtcl.sh

do-install:
	${INSTALL_DATA} ${WRKSRC}/mod_dtcl.so ${DESTDIR}${APACHEMODDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.gif ${DESTDIR}${HTMLDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.html ${DESTDIR}${HTMLDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} tests/README ${DESTDIR}${EGDIR}/tests
	cd ${WRKSRC}; ${INSTALL_DATA} tests/dtcl-test.tcl ${DESTDIR}${EGDIR}/tests
	cd ${WRKSRC}; ${INSTALL_DATA} tests/dtcl-test2.ttml ${DESTDIR}${EGDIR}/tests
	cd ${WRKSRC}; ${INSTALL_DATA} tests/dtcl.test ${DESTDIR}${EGDIR}/tests
	cd ${WRKSRC}; ${INSTALL_DATA} tests/makeconf.tcl ${DESTDIR}${EGDIR}/tests
	cd ${WRKSRC}; ${INSTALL_DATA} tests/runtests.tcl ${DESTDIR}${EGDIR}/tests
	cd ${WRKSRC}; ${INSTALL_DATA} tests/template.conf.tcl ${DESTDIR}${EGDIR}/tests
	cd ${WRKSRC}; ${INSTALL_DATA} contrib/*.ttml ${DESTDIR}${EGDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} contrib/*.tcl ${DESTDIR}${EGDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} docs/examples.ttml ${DESTDIR}${EGDIR}

.include "../../mk/bsd.pkg.mk"
