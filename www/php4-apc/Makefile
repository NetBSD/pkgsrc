# $NetBSD: Makefile,v 1.24 2006/06/02 18:28:01 joerg Exp $

MODNAME=	apc
PECL_VERSION=	2.0.4
CATEGORIES+=	sysutils
COMMENT=	Alternative PHP Cache for PHP4

MAINTAINER=	pkgsrc-users@NetBSD.org

CONFLICTS=	php-apc-[0-9]

CONFIGURE_ARGS+=	--enable-${MODNAME}
WRKSRC=		${WRKDIR}/APC-${PECL_VERSION}

PLIST_SRC+=		${.CURDIR}/PLIST.extras
PLIST_SUBST+=		PKGBASE=${PKGBASE:Q}
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCDIR}

PHP_VERSIONS_ACCEPTED=	4

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
