# $NetBSD: Makefile,v 1.5 1998/12/04 17:25:59 tv Exp $
#

DISTNAME=	mod_fastcgi-2.0.18
PKGNAME=	ap-fastcgi-2.0.18
CATEGORIES=	www
MASTER_SITES=	http://www.fastcgi.com/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.fastcgi.com/

DEPENDS+=	apache-1.3.3.2:../../www/apache
# For "apxs":
BUILD_DEPENDS=	${PREFIX}/bin/perl:../../lang/perl5

do-build:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -c -o mod_fastcgi.so \
		mod_fastcgi.c fcgibuf.c fcgios.c fcgitcl.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i mod_fastcgi.so
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_fastcgi
	${INSTALL_DATA} ${WRKSRC}/conf/httpd.conf \
		${PREFIX}/share/doc/mod_fastcgi/httpd.conf.example
	${INSTALL_DATA} ${WRKSRC}/docs/mod_fastcgi.html \
		${PREFIX}/share/httpd/htdocs/manual/mod/

.include "../../mk/bsd.pkg.mk"
