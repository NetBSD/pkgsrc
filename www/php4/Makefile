# $NetBSD: Makefile,v 1.38 2004/04/24 23:03:25 xtraeme Exp $

PKGNAME=		php-${PHP_BASE_VERS}
CATEGORIES+=		lang
COMMENT=		HTML-embedded scripting language

CONFLICTS+=		ap-php-4.0.3pl1

USE_BUILDLINK3=		YES
USE_PKGINSTALL=		YES
# PHP uses libtool inconsistently for CGI/CLI build; don't sanify for now
# LIBTOOL_OVERRIDE=	libtool
LIBTOOL_OVERRIDE=	# empty
USE_GNU_TOOLS+=		make

.include "Makefile.php"

CGIDIR=			${PREFIX}/libexec/cgi-bin
EGDIR=			${PREFIX}/share/examples/php

# On NetBSD ELF platforms, we need to link libgcc.a whole-archive so that
# certain symbols from the C++ implementation (__get_eh_context, etc.)
# referenced by DSOs written in C++ will resolve correctly.  We need to
# prefix the linker flags "-whole-archive -lgcc -no-whole-archive" with
# "-Wl," to force all of the flags to be passed down to the linker through
# libtool without change.
#
.if ${OPSYS} == "NetBSD" && ${OBJECT_FMT} == "ELF"
MAKE_ENV+=		LINK_LIBGCC_LDFLAGS="${LINK_ALL_LIBGCC_HACK}"
.endif

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}
MAKE_ENV+=		EXPORT_SYMBOLS_LDFLAGS="${EXPORT_SYMBOLS_LDFLAGS}"

CONF_FILES=	${EGDIR}/php.ini-recommended ${PKG_SYSCONFDIR}/php.ini
OWN_DIRS=	${PREFIX}/${PHP_EXTENSION_DIR}

post-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/cli/php ${PREFIX}/bin/php
	${INSTALL_DATA} ${WRKSRC}/sapi/cli/php.1 ${PREFIX}/man/man1/php.1
	${INSTALL_DATA_DIR} ${CGIDIR}
	${INSTALL_PROGRAM} ${WRKSRC}/sapi/cgi/php ${CGIDIR}
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} php.ini-dist php.ini-recommended ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/php
	${INSTALL_DATA} ${WRKSRC}/php.gif ${PREFIX}/share/php

.include "../../mk/bsd.pkg.mk"
