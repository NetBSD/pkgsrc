# $NetBSD: Makefile,v 1.18 2004/12/18 15:53:29 jdolecek Exp $

MODNAME=	apc
PECL_VERSION=	2.0.4
CATEGORIES+=	sysutils
COMMENT=	Alternative PHP Cache for PHP4

MAINTAINER=	tech-pkg@NetBSD.org

USE_BUILDLINK3=		YES

CONFIGURE_ARGS+=	--enable-${MODNAME}
WRKSRC=		${WRKDIR}/APC-${PECL_VERSION}

PLIST_SRC+=		${.CURDIR}/PLIST.extras
PLIST_SUBST+=		PKGBASE="${PKGBASE}"
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCDIR}

PHP_VERSION_REQD=	4		# PHP 4.x only

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
