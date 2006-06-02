# $NetBSD: Makefile,v 1.2 2006/06/02 18:28:00 joerg Exp $

MODNAME=	apc
PECL_VERSION=	3.0.10
CATEGORIES+=	sysutils
COMMENT=	Alternative PHP Cache

CONFLICTS=	php-apc-[0-9]

MAINTAINER=	pkgsrc-users@NetBSD.org

CONFIGURE_ARGS+=	--enable-${MODNAME}
WRKSRC=		${WRKDIR}/APC-${PECL_VERSION}

PLIST_SRC+=		${.CURDIR}/PLIST.extras
PLIST_SUBST+=		PKGBASE=${PKGBASE:Q}
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCDIR}

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
