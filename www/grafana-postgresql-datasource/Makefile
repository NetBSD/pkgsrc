# $NetBSD: Makefile,v 1.1 2026/10/21 17:14:16 tnn Exp $

DISTNAME=	grafana-postgresql-datasource-13.0.5
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=grafana/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/grafana/grafana-postgresql-datasource
COMMENT=	PostgreSQL data source for Grafana
LICENSE=	gnu-agpl-v3

DISTFILES=	${DEFAULT_DISTFILES}

FE_DISTNAME=			${DISTNAME}.linux_amd64.zip
DISTFILES+=			${FE_DISTNAME}
SITES.${FE_DISTNAME}=		https://github.com/grafana/grafana-postgresql-datasource/releases/download/v${PKGVERSION_NOREV}/
EXTRACT_DIR.${FE_DISTNAME}=	${WRKDIR}/linux
EXTRACT_ONLY=			${DEFAULT_DISTFILES} ${FE_DISTNAME}

USE_TOOLS+=		pax
GO_BUILD_PATTERN=	./pkg

.include "go-modules.mk"

PLUGINDIR=		share/grafana/plugins/grafana-postgresql-datasource
INSTALLATION_DIRS+=	${PLUGINDIR}

do-install:
	cd ${WRKDIR}/linux/grafana-postgresql-datasource && \
	  ${PAX} -rw . ${DESTDIR}${PREFIX}/${PLUGINDIR}/.
	${RM} -f ${DESTDIR}${PREFIX}/${PLUGINDIR}/gpx_grafana_postgresql_datasource_linux_amd64
	${RM} -f ${DESTDIR}${PREFIX}/${PLUGINDIR}/MANIFEST.txt
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/pkg ${DESTDIR}${PREFIX}/${PLUGINDIR}/gpx_grafana_postgresql_datasource_${GO_PLATFORM}

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
