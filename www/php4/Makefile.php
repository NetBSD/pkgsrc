# $NetBSD: Makefile.php,v 1.18 2004/10/03 00:18:27 tv Exp $

.include "../../www/php4/Makefile.common"

# revision of the core PHP interepreter package
PKGREVISION=		1

DISTINFO_FILE=		${.CURDIR}/../../www/php4/distinfo
PATCHDIR=		${.CURDIR}/../../www/php4/patches

USE_LIBTOOL=		YES
GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--without-mysql
CONFIGURE_ARGS+=	--without-iconv

CONFIGURE_ARGS+=	--disable-posix

CONFIGURE_ARGS+=	--with-config-file-path=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-exec-dir=${PREFIX}/libexec/php4
CONFIGURE_ARGS+=	--with-regex=system

CONFIGURE_ARGS+=	--enable-discard-path
CONFIGURE_ARGS+=	--enable-force-cgi-redirect
CONFIGURE_ARGS+=	--enable-memory-limit
CONFIGURE_ARGS+=	--enable-track-vars

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

# Global and legacy options
.if defined(USE_SSL) && !empty(USE_SSL:M[Yy][Ee][Ss])
PKG_DEFAULT_OPTIONS+=	ssl
.endif

PKG_OPTIONS_VAR=	PKG_OPTIONS.${PKGNAME:C/-[^-]*$//}
PKG_SUPPORTED_OPTIONS+=	ssl
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/openssl/buildlink3.mk"
CONFIGURE_ARGS+=	--with-openssl
.endif
