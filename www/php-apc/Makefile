# $NetBSD: Makefile,v 1.24 2013/11/24 07:11:11 dholland Exp $

MODNAME=	apc
PECL_VERSION=	3.1.13
PECL_LEGACY_VERSION_SCHEME=	yes
CATEGORIES+=	sysutils

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Alternative PHP Cache
LICENSE=	php


CONFLICTS=		php-apc-[0-9]*
PHP_VERSIONS_ACCEPTED=	54 53

CONFIGURE_ARGS+=	--enable-${MODNAME}
WRKSRC=			${WRKDIR}/APC-${PECL_VERSION}

PLIST_SRC+=		${.CURDIR}/PLIST.extras
PLIST_SUBST+=		PKGBASE=${PKGBASE:Q}

DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	${DOCDIR}

post-install:
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DESTDIR}${DOCDIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
