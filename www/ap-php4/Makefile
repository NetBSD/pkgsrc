# $NetBSD: Makefile,v 1.8 2001/02/17 17:21:52 wiz Exp $

.include "../../www/php4/Makefile.common"

PKGNAME=		ap-php-${PHP_VERS}

MAINTAINER=		jdolecek@netbsd.org
HOMEPAGE=		http://www.php.net/
COMMENT=		PHP4: Hypertext Preprocessor (Apache module)

DEPENDS+=		php-${PHP_VERS}:../../www/php4
DEPENDS+=		apache>=1.3:../../www/apache

# For "apxs":
BUILD_DEPENDS+=		${PERL5}:../../lang/perl5-base

CONFIGURE_ARGS+=	--with-apxs=${LOCALBASE}/sbin/apxs

do-install:
	${INSTALL_DATA} ${WRKSRC}/.libs/libphp4.so \
		${PREFIX}/lib/httpd/mod_php4.so

.include "../../mk/bsd.pkg.mk"
