# $NetBSD: Makefile.php,v 1.13 2004/04/26 08:35:22 jlam Exp $

.include "../../www/php4/Makefile.common"

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

BUILD_DEFS+=		USE_SSL
.if defined(USE_SSL) && !empty(USE_SSL:M[Yy][Ee][Ss])
PHP4_CONFIGURE_ARGS+=	--with-openssl
.include "../../security/openssl/buildlink3.mk"
.endif
