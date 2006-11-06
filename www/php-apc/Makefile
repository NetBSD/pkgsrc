# $NetBSD: Makefile,v 1.4 2006/11/06 21:11:46 jdolecek Exp $

MODNAME=	apc
PECL_VERSION=	3.0.12p2
CATEGORIES+=	sysutils
COMMENT=	Alternative PHP Cache

CONFLICTS=	php-apc-[0-9]*

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
