# $NetBSD: Makefile,v 1.9 1999/11/21 22:12:58 tron Exp $
#

DISTNAME=	mod_fastcgi_2.2.1
PKGNAME=	ap-fastcgi-2.2.1
CATEGORIES=	www
MASTER_SITES=	http://fastcgi.idle.com/dist/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.fastcgi.com/

DEPENDS+=	apache-1.3.*:../../www/apache
# For "apxs":
BUILD_DEPENDS=	${LOCALBASE}/bin/perl:../../lang/perl5

do-build:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -c -o mod_fastcgi.so *.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i mod_fastcgi.so
	${INSTALL_DATA} ${WRKSRC}/docs/mod_fastcgi.html \
		${PREFIX}/share/httpd/htdocs/manual/mod/

.include "../../mk/bsd.pkg.mk"
