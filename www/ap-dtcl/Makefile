# $NetBSD: Makefile,v 1.3 1999/11/21 22:12:59 tron Exp $

DISTNAME=	libapache-mod-dtcl_0.6.4-1
PKGNAME=	ap-dtcl-0.6.4
WRKSRC=		${WRKDIR}/mod_dtcl
CATEGORIES=	www
MASTER_SITES=	http://master.debian.org/~davidw/mod_dtcl/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://comanche.com.dtu.dk/dave/

DEPENDS+=	apache-1.3.*:../../www/apache
DEPENDS+=	tcl-*:../../lang/tcl80
# For "apxs":
BUILD_DEPENDS=	${LOCALBASE}/bin/perl:../../lang/perl5

INCLUDES=	-I${PREFIX}/include/tcl8.0
LIBS=		-L${PREFIX}/lib -Wl,-R${PREFIX}/lib -ltcl80 -lm

do-build:
	cd ${WRKSRC} && ${PREFIX}/sbin/apxs ${INCLUDES} ${LIBS} -c mod_dtcl.c
	cd ${WRKSRC} && ${CC} -DDEBUG_SCRIPT_DIR=\"${PREFIX}/libexec/mod_dtcl/\" \
		${INCLUDES} -o testdtcl testdtcl.c ${LIBS}
	${SED} -e s,/usr/lib,${PREFIX}/libexec,g < ${WRKSRC}/testdtcl.1 > ${WRKSRC}/testdtcl.1.new

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i mod_dtcl.so
	-${MKDIR} ${PREFIX}/share/doc/mod_dtcl
	${INSTALL_DATA} ${WRKSRC}/*.html ${PREFIX}/share/doc/mod_dtcl
	-${MKDIR} ${PREFIX}/share/examples/mod_dtcl
	${INSTALL_DATA} ${WRKSRC}/*.ttml ${PREFIX}/share/examples/mod_dtcl
	-${MKDIR} ${PREFIX}/libexec/mod_dtcl
	${INSTALL_DATA} ${WRKSRC}/*.tcl ${PREFIX}/libexec/mod_dtcl
	${INSTALL_PROGRAM} ${WRKSRC}/testdtcl ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/testdtcl.1.new ${PREFIX}/man/man1/testdtcl.1

.include "../../mk/bsd.pkg.mk"
