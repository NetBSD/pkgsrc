# $NetBSD: Makefile,v 1.1.1.1 1999/11/12 15:52:54 jwise Exp $

DISTNAME=	libapache-mod-dtcl_0.6.4-1
PKGNAME=	ap-dtcl-0.6.4
WRKSRC=		${WRKDIR}/mod_dtcl
CATEGORIES=	www
MASTER_SITES=	http://master.debian.org/~davidw/mod_dtcl/

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://comanche.com.dtu.dk/dave/

DEPENDS+=	apache-1.3.6p0:../../www/apache
DEPENDS+=	tcl-*:../../lang/tcl80
# For "apxs":
BUILD_DEPENDS=	${LOCALBASE}/bin/perl:../../lang/perl5

do-build:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -I${PREFIX}/include/tcl8.0 \
		-L${PREFIX}/lib -Wl,-R${PREFIX}/lib -ltcl80 -lm -c mod_dtcl.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i mod_dtcl.so
	-${MKDIR} ${PREFIX}/share/doc/mod_dtcl
	${CP} ${WRKSRC}/*.html ${PREFIX}/share/doc/mod_dtcl
	-${MKDIR} ${PREFIX}/share/examples/mod_dtcl
	${CP} ${WRKSRC}/*.tcl ${WRKSRC}/*.ttml ${PREFIX}/share/examples/mod_dtcl

.include "../../mk/bsd.pkg.mk"
