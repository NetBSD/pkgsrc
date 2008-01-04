# $NetBSD: Makefile,v 1.80 2008/01/04 10:07:52 adrianp Exp $

PKGNAME=		php-${PHP_BASE_VERS}
CATEGORIES+=		lang
COMMENT=		HTML-embedded scripting language

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		ap-php-4.0.3pl1

# PHP uses libtool inconsistently for CGI/CLI build; don't sanify for now
LIBTOOL_OVERRIDE=	# empty
USE_TOOLS+=		gmake lex

PKG_OPTIONS_REQUIRED_GROUPS+=	sapi
PKG_OPTIONS_GROUP.sapi=	cgi fastcgi
PKG_SUGGESTED_OPTIONS+=	cgi

.include "Makefile.php"

.if !empty(PKG_OPTIONS:Mcgi)
CONFIGURE_ARGS+=	--enable-discard-path
CONFIGURE_ARGS+=	--enable-force-cgi-redirect
.endif

.if !empty(PKG_OPTIONS:Mfastcgi)
CONFIGURE_ARGS+=	--enable-fastcgi
.endif

CGIDIR=			${PREFIX}/libexec/cgi-bin
EGDIR=			${PREFIX}/share/examples/php
MESSAGE_SUBST+=		CGIDIR=${CGIDIR:Q}

MAKE_ENV+=		INSTALL_ROOT=${DESTDIR}

# On NetBSD ELF platforms, we need to link libgcc.a whole-archive so that
# certain symbols from the C++ implementation (__get_eh_context, etc.)
# referenced by DSOs written in C++ will resolve correctly.  We need to
# prefix the linker flags "-whole-archive -lgcc -no-whole-archive" with
# "-Wl," to force all of the flags to be passed down to the linker through
# libtool without change.
#
.if ${OPSYS} == "NetBSD" && ${OBJECT_FMT} == "ELF"
MAKE_ENV+=		LINK_LIBGCC_LDFLAGS=${LINK_ALL_LIBGCC_HACK:Q}
.endif

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}
MAKE_ENV+=		EXPORT_SYMBOLS_LDFLAGS=${EXPORT_SYMBOLS_LDFLAGS:Q}

CONF_FILES=	${EGDIR}/php.ini-recommended ${PKG_SYSCONFDIR}/php.ini
OWN_DIRS=	${PREFIX}/${PHP_EXTENSION_DIR}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/cli/php \
		${DESTDIR:Q}${PREFIX:Q}/bin/php
	${INSTALL_DATA} ${WRKSRC}/sapi/cli/php.1 \
		${DESTDIR:Q}${PREFIX:Q}/${PKGMANDIR}/man1/php.1
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${CGIDIR:Q}
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/cgi/php ${DESTDIR:Q}${CGIDIR:Q}
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${EGDIR:Q}
	cd ${WRKSRC}; ${INSTALL_DATA} php.ini-dist php.ini-recommended \
		${DESTDIR:Q}${EGDIR:Q}
	${INSTALL_DATA_DIR} ${DESTDIR:Q}${PREFIX:Q}/share/php
	${INSTALL_DATA} ${WRKSRC}/php.gif ${DESTDIR:Q}${PREFIX:Q}/share/php

.include "../../mk/bsd.pkg.mk"
