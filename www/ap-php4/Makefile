# $NetBSD: Makefile,v 1.10 2001/03/28 17:56:09 jlam Exp $

.include "../../www/php4/Makefile.common"

PKGNAME=		ap-php-${PHP_BASE_VERS}nb1

COMMENT=		PHP4: Hypertext Preprocessor (Apache module)

DEPENDS+=		php-${PHP_VERS}:../../www/php4
DEPENDS+=		apache>=1.3:../../www/apache

# For "apxs":
BUILD_DEPENDS+=		perl-5.*:../../lang/perl5

CONFIGURE_ARGS+=	--with-apxs=${LOCALBASE}/sbin/apxs

do-install:
	${INSTALL_DATA} ${WRKSRC}/.libs/libphp4.so \
		${PREFIX}/lib/httpd/mod_php4.so

.include "../../mk/bsd.pkg.mk"
