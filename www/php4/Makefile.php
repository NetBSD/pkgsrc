# $NetBSD: Makefile.php,v 1.1 2001/10/16 04:54:24 jlam Exp $

.include "../php4/Makefile.common"

DISTINFO_FILE=		${.CURDIR}/../php4/distinfo
PATCHDIR=		${.CURDIR}/../php4/patches

USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		YES

CONFIGURE_ARGS+=	--without-mysql
CONFIGURE_ARGS+=	--without-pcre-regex

CONFIGURE_ARGS+=	--disable-posix
CONFIGURE_ARGS+=	--disable-session
CONFIGURE_ARGS+=	--disable-xml

CONFIGURE_ARGS+=	--with-config-file-path=${PHP_CONFDIR}
CONFIGURE_ARGS+=	--with-exec-dir=${PREFIX}/libexec/php4
CONFIGURE_ARGS+=	--with-regex=system

CONFIGURE_ARGS+=	--enable-discard-path
CONFIGURE_ARGS+=	--enable-force-cgi-redirect
CONFIGURE_ARGS+=	--enable-memory-limit
CONFIGURE_ARGS+=	--enable-track-vars

CONFIGURE_ENV+=		ac_cv_lib_pam_pam_start=no

post-configure: create-shlibtool

create-shlibtool:
	cd ${WRKSRC}; ${RM} -f shlibtool; ${LN} -sf libtool shlibtool
