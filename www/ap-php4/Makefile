# $NetBSD: Makefile,v 1.4 2000/12/17 17:18:01 jlam Exp $

.include "../../www/php4/Makefile.common"

PKGNAME=		ap-${DISTNAME}nb1
CATEGORIES+=		lang

MAINTAINER=		jdolecek@netbsd.org
HOMEPAGE=		http://www.php.net/

DEPENDS+=		php-${PHP_VERS}:../../www/php4
DEPENDS+=		apache>=1.3:../../www/apache

CONFIGURE_ARGS+=	--with-apxs=${LOCALBASE}/sbin/apxs

do-install:
	${INSTALL_DATA} ${WRKSRC}/.libs/libphp4.so \
		${PREFIX}/lib/httpd/mod_php4.so

.include "../../mk/bsd.pkg.mk"
