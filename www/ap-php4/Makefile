# $NetBSD: Makefile,v 1.12 2001/05/03 13:40:33 jlam Exp $

.include "../../www/php4/Makefile.common"

PKGNAME=		ap-php-${PHP_BASE_VERS}nb1

COMMENT=		PHP4: Hypertext Preprocessor (Apache module)

DEPENDS+=		php-${PHP_VERS}:../../www/php4
DEPENDS+=		apache>=1.3:../../www/apache

# For "apxs":
BUILD_DEPENDS+=		perl>=${PERL5_REQD}:../../lang/perl5

CONFIGURE_ARGS+=	--with-apxs=${LOCALBASE}/sbin/apxs

# Ensure we export symbols in the linked ELF shared object.
.if (${OBJECT_FMT} == "ELF")
LDFLAGS+=		-Wl,-E
.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/.libs/libphp4.so 			\
		${PREFIX}/lib/httpd/mod_php4.so

.include "../../mk/bsd.pkg.mk"
