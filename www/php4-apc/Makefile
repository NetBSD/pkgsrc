# $NetBSD: Makefile,v 1.13 2004/11/02 20:08:15 jdolecek Exp $

DISTNAME=	APC-2.0.4
PKGNAME=	php-${DISTNAME:tl}
MODNAME=	${DISTNAME:C/-[^-]*$//:tl}
CATEGORIES+=	sysutils
MASTER_SITES=	http://pecl.php.net/get/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://apc.communityconnect.com/
COMMENT=	Alternative PHP Cache for PHP4

EXTRACT_ELEMENTS=	# empty

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_BUILDLINK3=		YES
DISTINFO_FILE=		${.CURDIR}/distinfo

PHP_VERSION_REQD=	4		# PHP 4.x only
.include "../../lang/php/ext.mk"

CONFIGURE_ARGS+=	--enable-${MODNAME}

PLIST_SRC+=		${.CURDIR}/PLIST.extras
PLIST_SUBST+=		PKGBASE="${PKGBASE}"
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} \
		INSTALL LICENSE NOTICE ${DOCDIR}

.include "../../mk/bsd.pkg.mk"
