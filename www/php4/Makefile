# $NetBSD: Makefile,v 1.19 2001/12/02 06:56:47 jlam Exp $

.include "Makefile.php"

PKGNAME=		php-${PHP_VERS}
PHP_PKG_VERS=		# empty
CATEGORIES+=		lang
COMMENT=		HTML-embedded scripting language

CONFLICTS+=		ap-php-4.0.3pl1

USE_BUILDLINK_ONLY=	YES

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		-Wl,--export-dynamic

CGIDIR=			${PREFIX}/libexec/cgi-bin
EGDIR=			${PREFIX}/share/examples/php

# On NetBSD ELF platforms, we need to link libgcc.a whole-archive so that
# certain symbols from the C++ implementation (__get_eh_context, etc.)
# referenced by DSOs written in C++ will resolve correctly.  We need to
# prefix the linker flags "-whole-archive -lgcc -no-whole-archive" with
# "-Wl," to force all of the flags to be passed down to the linker through
# libtool without change.
#
.if (${OPSYS} == "NetBSD") && (${OBJECT_FMT} == "ELF")
LINK_LIBGCC_LDFLAGS=	-Wl,--whole-archive -Wl,-lgcc -Wl,--no-whole-archive
MAKE_ENV+=		LINK_LIBGCC_LDFLAGS="${LINK_LIBGCC_LDFLAGS}"
.endif

CONF_FILES=	${EGDIR}/php.ini-dist ${PKG_SYSCONFDIR}/php.ini

post-install:
	${INSTALL_DATA_DIR} ${CGIDIR}
	${LN} -sf ../../bin/php ${CGIDIR}/php
	${TOUCH} ${PREFIX}/${PHP_EXTENSION_DIR}/.directory
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} php.ini-dist php.ini-optimized ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/php
	${INSTALL_DATA} ${WRKSRC}/php4.gif ${PREFIX}/share/php

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
