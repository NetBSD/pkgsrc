# $NetBSD: Makefile,v 1.1.1.1 2000/12/17 09:19:32 jlam Exp $

.include "../../www/php4/Makefile.common"

CATEGORIES+=		www lang

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.php.net/

CONFLICTS+=		ap-php-4.0.3pl1

EXTRACT_ELEMENTS=	${DISTNAME}/php.ini-dist
EXTRACT_ELEMENTS+=	${DISTNAME}/php.ini-optimized
EXTRACT_ELEMENTS+=	${DISTNAME}/php4.gif

MESSAGE_FILE=		${WRKDIR}/.MESSAGE

# This package only installs some PHP4-related files, and doesn't require
# any of these steps.
#
NO_PATCH=		# defined
NO_CONFIGURE=		# defined
NO_BUILD=		# defined

pre-install:
	${SED}	-e "s,@PREFIX@,${PREFIX},g" \
		< ${PKGDIR}/MESSAGE > ${MESSAGE_FILE}

do-install:
	${INSTALL_DATA} ${WRKSRC}/php.ini-dist ${PREFIX}/etc
	${INSTALL_DATA} ${WRKSRC}/php.ini-optimized ${PREFIX}/etc
	${INSTALL_DATA_DIR} ${PREFIX}/share/php4
	${INSTALL_DATA} ${WRKSRC}/php4.gif ${PREFIX}/share/php4

.include "../../mk/bsd.pkg.mk"
