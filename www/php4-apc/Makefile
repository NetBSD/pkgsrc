# $NetBSD: Makefile,v 1.12 2004/04/24 23:03:25 xtraeme Exp $

DISTNAME=	apc-1.1.0pl1
PKGNAME=	php-apc-1.1.0.1
MODNAME=	${DISTNAME:C/-[^-]*$//}
CATEGORIES+=	www
MASTER_SITES=	http://apc.communityconnect.com/sources/
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://apc.communityconnect.com/
COMMENT=	Alternative PHP Cache for PHP4

EXTRACT_ELEMENTS=	# empty

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_BUILDLINK3=		YES
DISTINFO_FILE=		${.CURDIR}/distinfo

.include "../../www/php4/Makefile.module"

CONFIGURE_ARGS+=	--enable-${MODNAME}

PLIST_SRC+=		${.CURDIR}/PLIST.extras
PLIST_SUBST+=		PKGBASE="${PKGBASE}"
DOCDIR=			${PREFIX}/share/doc/${PKGBASE}
EGDIR=			${PREFIX}/share/examples/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR} ${EGDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} \
		GORY_DETAILS INSTALL LICENSE README.compiler ${DOCDIR}
	cd ${WRKSRC}; ${INSTALL_DATA} extras/apcinfo.php ${EGDIR}

.include "../../mk/bsd.pkg.mk"
