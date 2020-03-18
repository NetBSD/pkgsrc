# $NetBSD: Makefile,v 1.17 2020/03/18 18:03:29 joerg Exp $
#

DISTNAME=	aipo-${VERSION}-linux-x86
VERSION=	8.0.1
PKGNAME=	aipo-${VERSION}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_OSDN:=aipo/63319/}
EXTRACT_SUFX=	.gz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://www.aipo.com/
COMMENT=	Web-based groupware that supports Japanese interface
LICENSE=	gnu-agpl-v3

USE_JAVA=	run
USE_JAVA2=	6

NO_BUILD=	yes

USE_LANGUAGES=	# none

USE_TOOLS+=	pax tar unzip

INSTALLATION_DIRS=	share/aipo/ROOT share/aipo/container share/examples/aipo

SUBST_CLASSES+=			username
SUBST_STAGE.username=		pre-configure
SUBST_MESSAGE.username=		Set default username and password
SUBST_FILES.username=		dist/ROOT/WEB-INF/datasource/dbcp-org001.properties
SUBST_SED.username=		-e 's,cayenne.dbcp.username=postgres,cayenne.dbcp.username=aipo_pgsql,'
SUBST_SED.username+=		-e 's,cayenne.dbcp.password=aipo,cayenne.dbcp.password=aipo_db_password,'

CONF_FILES+=	${PREFIX}/share/examples/aipo/securityTokenKey.txt \
		${PREFIX}/share/aipo/ROOT/WEB-INF/conf/securityTokenKey.txt
CONF_FILES+=	${PREFIX}/share/examples/aipo/dbcp-org001.properties \
		${PREFIX}/share/aipo/ROOT/WEB-INF/datasource/dbcp-org001.properties
 

post-extract:
	cd ${WRKDIR} && mv aipo-${VERSION}-linux-x86 aipo-${VERSION}-linux-x86.tar
	cd ${WRKDIR} && ${TAR} xf aipo-${VERSION}-linux-x86.tar
	${UNZIP_CMD} -d ${WRKSRC}/dist/ROOT \
		${WRKSRC}/dist/aipo.war

do-install:
	cd ${WRKSRC}/dist && pax -rw ROOT license sql \
		${DESTDIR}${PREFIX}/share/aipo
	${INSTALL_DATA} ${WRKSRC}/dist/postgresql-9.3-1103.jdbc41.jar \
		${DESTDIR}${PREFIX}/share/aipo/ROOT/WEB-INF/lib
	mv ${DESTDIR}${PREFIX}/share/aipo/ROOT/WEB-INF/datasource/dbcp-org001.properties \
		${DESTDIR}${PREFIX}/share/examples/aipo
	mv ${DESTDIR}${PREFIX}/share/aipo/ROOT/WEB-INF/conf/securityTokenKey.txt \
		${DESTDIR}${PREFIX}/share/examples/aipo
	find ${DESTDIR}${PREFIX}/share/aipo -type f -exec chmod 644 {} \;
	find ${DESTDIR}${PREFIX}/share/examples/aipo -type f -exec chmod 644 {} \;

.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
