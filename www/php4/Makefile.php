# $NetBSD: Makefile.php,v 1.37 2007/05/05 21:35:05 adrianp Exp $

.include "../../www/php4/Makefile.common"

# revision of the core PHP interpreter package
DISTINFO_FILE=		${.CURDIR}/../../www/php4/distinfo
PATCHDIR=		${.CURDIR}/../../www/php4/patches

BUILD_DEFS+=		USE_INET6

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--without-mysql
CONFIGURE_ARGS+=	--without-iconv
CONFIGURE_ARGS+=	--without-pear

CONFIGURE_ARGS+=	--disable-posix

CONFIGURE_ARGS+=	--with-config-file-path=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-exec-dir=${PREFIX}/libexec/php4

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS+=	--with-regex=system

# Support for linking some PHP4 extensions statically into the php CGI and
# into the apache mod_php.so DSO.
#
# PHP4_CONFIGURE_ARGS should contain GNU configure options, a complete
# list of which may be found at:
#
#	http://www.php.net/manual/en/install.configure.php
#
# Note that this is generally not needed as many of the extensions (mysql,
# pgsql) may be dynamically loaded, and are separately packaged in pkgsrc.
#
PHP4_CONFIGURE_ARGS?=	# empty
CONFIGURE_ARGS+=	${PHP4_CONFIGURE_ARGS}

CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=no
CONFIGURE_ENV+=		EXTENSION_DIR="${PREFIX}/${PHP_EXTENSION_DIR}"

# Note: This expression is the same as ${PKGBASE}, but the latter is
# not defined yet, so we cannot use it here.
PKG_OPTIONS_VAR=	PKG_OPTIONS.${PKGNAME:C/-[0-9].*//}
PKG_SUPPORTED_OPTIONS+=	inet6 ssl
PKG_SUGGESTED_OPTIONS+=	ssl

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=	--enable-ipv6
.else
CONFIGURE_ARGS+=	--disable-ipv6
.endif

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
.else
CONFIGURE_ARGS+=	--without-openssl
.endif
