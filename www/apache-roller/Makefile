# $NetBSD: Makefile,v 1.1.1.1 2009/02/12 00:26:59 adrianp Exp $
#

DISTNAME=	apache-roller-4.0.1
CATEGORIES=	www
MASTER_SITES=	http://mirror.lividpenguin.com/pub/apache/roller/roller-4/v4.0.1/bin/
EXTRACT_SUFX=	.zip

MAINTAINER=	adrianp@NetBSD.org
HOMEPAGE=	http://roller.apache.org/
COMMENT=	Full-featured, multi-user and group-blog server

USE_JAVA=	run
USE_JAVA2=	1.5

PKG_DESTDIR_SUPPORT=	user-destdir
PLIST_SUBST+=		PKGNAME_NOREV=${PKGNAME_NOREV:Q}

.include "options.mk"

do-build:
	cd ${WRKSRC}/webapp/roller && ${PKG_JAVA_HOME}/bin/jar cvf \
		../${PKGNAME_NOREV}.war *

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/apache-roller
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/apache-roller
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/apache-roller

	${INSTALL_DATA} ${WRKSRC}/docs/roller-*.pdf \
		${DESTDIR}${PREFIX}/share/doc/apache-roller
	${INSTALL_DATA} ${WRKSRC}/*.txt \
		${DESTDIR}${PREFIX}/share/doc/apache-roller
	${INSTALL_DATA} ${WRKSRC}/webapp/${PKGNAME_NOREV}.war \
		${DESTDIR}${PREFIX}/share/apache-roller
	${INSTALL_DATA} ${FILESDIR}/roller-custom.properties \
		${DESTDIR}${PREFIX}/share/examples/apache-roller

.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/java-vm.mk"
.include "../../mk/bsd.pkg.mk"
