# $NetBSD: Makefile,v 1.16 2001/10/20 17:46:50 jlam Exp $

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

DEINSTALL_FILE=		${WRKDIR}/DEINSTALL
INSTALL_FILE=		${WRKDIR}/INSTALL

FILES_SUBST=		PHP_CONFDIR=${PHP_CONFDIR}
FILES_SUBST+=		CAT=${CAT:Q}
FILES_SUBST+=		CHMOD=${CHMOD:Q}
FILES_SUBST+=		CMP=${CMP:Q}
FILES_SUBST+=		CP=${CP:Q}
FILES_SUBST+=		RM=${RM:Q}
FILES_SUBST_SED=	${FILES_SUBST:S/=/@!/:S/$/!g/:S/^/ -e s!@/}

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

pre-install:
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/DEINSTALL > ${DEINSTALL_FILE}
	${SED} ${FILES_SUBST_SED} ${PKGDIR}/INSTALL > ${INSTALL_FILE}
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} PRE-INSTALL

post-install:
	${INSTALL_DATA_DIR} ${CGIDIR}
	${LN} -sf ../../bin/php ${CGIDIR}/php
	${TOUCH} ${PREFIX}/${PHP_EXTENSION_DIR}/.directory
	${INSTALL_DATA_DIR} ${EGDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} php.ini-dist php.ini-optimized ${EGDIR}
	${INSTALL_DATA_DIR} ${PREFIX}/share/php
	${INSTALL_DATA} ${WRKSRC}/php4.gif ${PREFIX}/share/php
	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
