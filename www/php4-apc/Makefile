# $NetBSD: Makefile,v 1.23 2006/03/04 21:31:03 jlam Exp $

MODNAME=	apc
PECL_VERSION=	2.0.4
PKGREVISION=	2
CATEGORIES+=	sysutils
COMMENT=	Alternative PHP Cache for PHP4

MAINTAINER=	pkgsrc-users@NetBSD.org


CONFIGURE_ARGS+=	--enable-${MODNAME}
WRKSRC=		${WRKDIR}/APC-${PECL_VERSION}

PLIST_SRC+=		${.CURDIR}/PLIST.extras
PLIST_SUBST+=		PKGBASE=${PKGBASE:Q}
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${DOCDIR}

PHP_VERSION_REQD=	4		# PHP 4.x only

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
