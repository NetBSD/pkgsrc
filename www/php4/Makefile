# $NetBSD: Makefile,v 1.23 2002/02/28 06:14:46 jlam Exp $

PKGNAME=		php-${PHP_BASE_VERS}
PKGREVISION=		# empty
CATEGORIES+=		lang
COMMENT=		HTML-embedded scripting language

CONFLICTS+=		ap-php-4.0.3pl1

USE_BUILDLINK_ONLY=	YES

.include "Makefile.php"

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

CONF_FILES=	${EGDIR}/php.ini-recommended ${PKG_SYSCONFDIR}/php.ini
OWN_DIRS=	${PREFIX}/${PHP_EXTENSION_DIR}

post-install:
	${RMDIR} ${PREFIX}/include/php/ext/xml/expat/xmltok
	${RMDIR} ${PREFIX}/include/php/ext/xml/expat/xmlparse
	${RMDIR} ${PREFIX}/include/php/ext/xml/expat
	${INSTALL_DATA_DIR} ${CGIDIR}
	${LN} -sf ../../bin/php ${CGIDIR}/php
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} php.ini-dist php.ini-recommended ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/php
	${INSTALL_DATA} ${WRKSRC}/php4.gif ${PREFIX}/share/php

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
