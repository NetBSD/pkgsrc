# $NetBSD: Makefile,v 1.2 1998/10/05 14:27:19 tv Exp $
#

DISTNAME=	mod_fastcgi-2.0.17
PKGNAME=	ap-fastcgi-2.0.17
CATEGORIES=	www
MASTER_SITES=	http://www.fastcgi.com/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.fastcgi.com/

BUILD_DEPENDS+=	${PREFIX}/sbin/apxs:../../www/apache
RUN_DEPENDS+=	${PREFIX}/sbin/apxs:../../www/apache

USE_PERL5=	yes	# for "apxs"

do-build:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -c -o mod_fastcgi.so \
		mod_fastcgi.c fcgibuf.c fcgios.c fcgitcl.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i mod_fastcgi.so
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mod_fastcgi
	${INSTALL_DATA} ${WRKSRC}/docs/mod_fastcgi.html \
		${PREFIX}/share/doc/mod_fastcgi/
	${INSTALL_DATA} ${WRKSRC}/conf/httpd.conf \
		${PREFIX}/share/doc/mod_fastcgi/httpd.conf.example

.include "../../mk/bsd.pkg.mk"
