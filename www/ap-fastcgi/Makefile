# $NetBSD: Makefile,v 1.12 2000/08/28 09:14:51 jlam Exp $
#

DISTNAME=	mod_fastcgi_2.2.4
PKGNAME=	ap-fastcgi-2.2.4
CATEGORIES=	www
MASTER_SITES=	http://www.fastcgi.com/dist/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.fastcgi.com/

DEPENDS+=	apache-1.3.*:../../www/apache
# For "apxs":
BUILD_DEPENDS=	${PERL5}:../../lang/perl5

do-build:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -c -o mod_fastcgi.so *.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i mod_fastcgi.so
	${INSTALL_DATA} ${WRKSRC}/docs/mod_fastcgi.html \
		${PREFIX}/share/httpd/htdocs/manual/mod/

.include "../../mk/bsd.pkg.mk"
