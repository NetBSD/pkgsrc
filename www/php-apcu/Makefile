# $NetBSD: Makefile,v 1.26 2024/09/22 14:58:18 taca Exp $

MODNAME=	apcu
PECL_VERSION=	5.1.24
CATEGORIES+=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	APCu - APC User Cache
LICENSE=	php

PHP_VERSIONS_INCOMPATIBLE=	56

GNU_CONFIGURE_STRICT=	no # --with-pcre-dir is added for all PHP extensions
CONFIGURE_ARGS+=	--enable-${MODNAME}

# Use spinlocks if available
# XXX Default is fnctl, and implentation leaks
# file descriptors on apachectl graceful
.if ${MACHINE_ARCH} == i386 || ${MACHINE_ARCH} == x86_64
CONFIGURE_ARGS+=	--enable-apcu-spinlocks
.endif


PLIST_SRC+=		${.CURDIR}/PLIST.extras
PLIST_SUBST+=		PKGBASE=${PKGBASE}

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	cd ${WRKSRC} && ${MAKE} INSTALL_ROOT="${DESTDIR}" install-headers

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
