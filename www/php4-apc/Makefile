# $NetBSD: Makefile,v 1.6 2003/07/17 22:55:59 grant Exp $

DISTNAME=	apc-1.1.0pl1
PKGNAME=	php-apc-1.1.0.1
MODNAME=	${DISTNAME:C/-[^-]*$//}
WRKSRC=		${WRKDIR}/${DISTNAME}
CATEGORIES+=	www
MASTER_SITES=	http://apc.communityconnect.com/sources/

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://apc.communityconnect.com/
COMMENT=	Alternative PHP Cache for PHP4

EXTRACT_ELEMENTS=	# empty

USE_BUILDLINK2=		YES

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

.include "../../www/php4/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
