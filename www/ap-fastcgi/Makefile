# $NetBSD: Makefile,v 1.19 2001/05/20 05:23:27 jonb Exp $
#

DISTNAME=	mod_fastcgi_2.2.10
PKGNAME=	ap-fastcgi-2.2.10
CATEGORIES=	www
MASTER_SITES=	http://www.fastcgi.com/dist/

MAINTAINER=	tv@netbsd.org
HOMEPAGE=	http://www.fastcgi.com/
COMMENT=	New, improved CGI-like interface module for Apache

DEPENDS+=	apache{,6}-1.3.*:../../www/apache
# For "apxs":
BUILD_DEPENDS=	perl>=${PERL5_REQD}:../../lang/perl5

do-build:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -c -o mod_fastcgi.so *.c

do-install:
	@cd ${WRKSRC} && ${PREFIX}/sbin/apxs -i mod_fastcgi.so
	${INSTALL_DATA} ${WRKSRC}/docs/mod_fastcgi.html \
		${PREFIX}/share/httpd/htdocs/manual/mod/

.include "../../mk/bsd.pkg.mk"
