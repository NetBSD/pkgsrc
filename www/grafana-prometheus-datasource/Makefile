# $NetBSD: Makefile,v 1.3 2026/08/30 15:03:27 wiz Exp $

DISTNAME=	grafana-prometheus-datasource-13.1.9
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=grafana/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/grafana/grafana-prometheus-datasource
COMMENT=	Prometheus data source for Grafana
LICENSE=	gnu-agpl-v3

DISTFILES=	${DEFAULT_DISTFILES}

FE_DISTNAME=			prometheus-13.1.9.linux_amd64.zip
DISTFILES+=			${FE_DISTNAME}
SITES.${FE_DISTNAME}=		https://github.com/grafana/grafana-prometheus-datasource/releases/download/v${PKGVERSION_NOREV}/
EXTRACT_DIR.${FE_DISTNAME}=	${WRKDIR}/linux
EXTRACT_ONLY=			${DEFAULT_DISTFILES} ${FE_DISTNAME}

USE_TOOLS+=		pax
GO_BUILD_PATTERN=	./pkg

.include "go-modules.mk"

PLUGINDIR=		share/grafana/plugins/prometheus

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}${PLUGINDIR}
	cd ${WRKDIR}/linux/prometheus && \
	  ${PAX} -rw . ${DESTDIR}${PREFIX}/${PLUGINDIR}/.
	${RM} -f ${DESTDIR}${PREFIX}/${PLUGINDIR}/gpx_grafana-prometheus-datasource_linux_amd64
	${RM} -f ${DESTDIR}${PREFIX}/${PLUGINDIR}/MANIFEST.txt
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/pkg ${DESTDIR}${PREFIX}/${PLUGINDIR}/gpx_grafana-prometheus-datasource_${GO_PLATFORM}

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
