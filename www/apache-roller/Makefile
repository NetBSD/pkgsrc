# $NetBSD: Makefile,v 1.13 2015/05/19 21:28:27 spz Exp $
#

DISTNAME=	roller-release-${ROLLER_VER}-standard
PKGNAME=	apache-roller-${ROLLER_VER}
WRKSRC=		${WRKDIR}/${DISTNAME:S/-standard//}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_APACHE:=roller/roller-5.1/v${ROLLER_VER}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://roller.apache.org/
LICENSE=	apache-2.0
COMMENT=	Full-featured, multi-user and group-blog server

BUILD_DEPENDS+=	fastjar-[0-9]*:../../archivers/fastjar

USE_JAVA=	run
USE_JAVA2=	1.5
ROLLER_VER=	5.1.2

PLIST_SUBST+=		PKGNAME_NOREV=${PKGNAME_NOREV:Q}

.include "options.mk"

do-build:
	:

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/apache-roller
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/apache-roller
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/apache-roller

	${INSTALL_DATA} ${WRKSRC}/docs/roller-*.odt \
		${DESTDIR}${PREFIX}/share/doc/apache-roller
	${INSTALL_DATA} ${WRKSRC}/*.txt \
		${DESTDIR}${PREFIX}/share/doc/apache-roller
	${INSTALL_DATA} ${WRKSRC}/webapp/roller.war \
		${DESTDIR}${PREFIX}/share/apache-roller/${PKGNAME_NOREV}.war
	${INSTALL_DATA} ${FILESDIR}/roller-custom.properties \
		${DESTDIR}${PREFIX}/share/examples/apache-roller

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
