# $NetBSD: Makefile,v 1.8 2016/07/09 13:11:58 rillig Exp $
#

DISTNAME=	mserv-php-090
PKGNAME=	mserv-php-0.90
PKGREVISION=	1
CATEGORIES=	audio www
MASTER_SITES=	# 404: http://dougiamas.com/mserv/src/
EXTRACT_SUFX=	.tgz

MAINTAINER=	abs@absd.org
HOMEPAGE=	# 404: http://dougiamas.com/mserv/
COMMENT=	Quick web interface to mserv audio jukebox

DEPENDS+=	mserv-[0-9]*:../../audio/mserv

WRKSRC=		${WRKDIR}/mserv-php

LICENSE=	gnu-gpl-v2

MSERVPHPDIR=	${PREFIX}/share/mserv-php
DOCDIR=		${PREFIX}/share/doc/mserv-php

SUBST_CLASSES+=		paths
SUBST_FILES.paths=	${WRKDIR}/config.php
SUBST_SED.paths+=	-e 's,@PREFIX@,${PREFIX},g'
SUBST_STAGE.paths=	post-build

INSTALLATION_DIRS+=	share/mserv-php share/mserv-php/image share/doc/mserv-php

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

.include "../../lang/php/phpversion.mk"
.include "${PHPPKGSRCDIR}/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
