# $NetBSD: Makefile,v 1.12 2014/06/10 14:21:37 joerg Exp $
#

DISTNAME=	aipo${VERSION:S/.//g}0ja_linux32
VERSION=	7.0.2
PKGNAME=	aipo-${VERSION}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://aipo.googlecode.com/files/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.aipo.com/
COMMENT=	Web-based groupware that supports Japanese interface
LICENSE=	gnu-agpl-v3

DEPENDS=	jdbc-postgresql92-[0-9]*:../../databases/jdbc-postgresql92

USE_JAVA=	run
USE_JAVA2=	6

NO_BUILD=	yes

WRKSRC=		${WRKDIR}/aipo${VERSION:S/.//g}0ja_linux
USE_LANGUAGES=	# none

USE_TOOLS+=	gunzip pax tar

AIPO_DIR=	share/aipo
TOMCAT_DIR=	share/tomcat

INSTALLATION_DIRS=	share/tomcat/lib ${AIPO_DIR}/webapps/aipo/WEB-INF

SUBST_CLASSES+=			username
SUBST_STAGE.username=		pre-configure
SUBST_MESSAGE.username=		Set default username and password
SUBST_FILES.username=		aipo/src/webapps/aipo/WEB-INF/datasource/dbcp-org001.properties
SUBST_FILES.username+=		aipo/src/webapps/ROOT/WEB-INF/datasource/dbcp-org001.properties
SUBST_SED.username=		-e 's,cayenne.dbcp.username=postgres,cayenne.dbcp.username=aipo_pgsql,'
SUBST_SED.username+=		-e 's,cayenne.dbcp.password=aipo,cayenne.dbcp.password=aipo_db_password,'

post-extract:
	cd ${WRKSRC} && ${GUNZIP_CMD} -c aipo${VERSION:S/.//g}0.tar.gz | ${TAR} -xpf -

do-install:
	cd  ${WRKSRC}/aipo/src/webapps && \
		pax -rw aipo ROOT ${DESTDIR}${PREFIX}/${AIPO_DIR}/webapps
	cd  ${WRKSRC}/aipo/src/initdata && \
		pax -rw psml files mail sql \
			${DESTDIR}${PREFIX}/${AIPO_DIR}/webapps/aipo/WEB-INF
	${INSTALL_DATA} ${PREFIX}/lib/java/postgresql92.jar \
			${DESTDIR}${PREFIX}/${TOMCAT_DIR}/lib
	${INSTALL_DATA} ${WRKSRC}/aipo/src/tools.jar \
			${DESTDIR}${PREFIX}/${TOMCAT_DIR}/lib

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
