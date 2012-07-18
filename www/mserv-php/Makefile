# $NetBSD: Makefile,v 1.3 2012/07/18 20:36:06 cheusov Exp $
#

DISTNAME=	mserv-php-090
PKGNAME=	mserv-php-0.90
CATEGORIES=	audio www
MASTER_SITES=	http://dougiamas.com/mserv/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://dougiamas.com/mserv/
COMMENT=	Quick web interface to mserv audio jukebox

DEPENDS+=       mserv-[0-9]*:../../audio/mserv
DEPENDS+=	php>=4.0.6:../../lang/php53

WRKSRC=		${WRKDIR}/mserv-php

LICENSE=	gnu-gpl-v2

MSERVPHPDIR=	${PREFIX}/share/mserv-php
DOCDIR=		${PREFIX}/share/doc/mserv-php

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/config.php
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_STAGE.paths=	post-build

PKG_DESTDIR_SUPPORT = user-destdir
INSTALLATION_DIRS += share/mserv-php share/mserv-php/image share/doc/mserv-php

do-build:
	${CP} ${WRKSRC}/config.php ${WRKDIR}/config.php

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.php ${DESTDIR}${MSERVPHPDIR}
	${INSTALL_DATA} ${WRKDIR}/config.php ${DESTDIR}${MSERVPHPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.css ${DESTDIR}${MSERVPHPDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${DESTDIR}${MSERVPHPDIR}
	${INSTALL_DATA} ${WRKSRC}/image/*.gif ${DESTDIR}${MSERVPHPDIR}/image
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${MSERVPHPDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYRIGHT.GPL ${DESTDIR}${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/README-0.90 ${DESTDIR}${DOCDIR}

.include "../../mk/bsd.pkg.mk"
