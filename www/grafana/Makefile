# $NetBSD: Makefile,v 1.27 2020/04/12 11:01:49 bsiegert Exp $

DISTNAME=	grafana-6.3.4
PKGREVISION=	8
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=grafana/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	https://grafana.com/
COMMENT=	Metrics dashboard and graph editor
LICENSE=	apache-2.0

DISTFILES=	${DEFAULT_DISTFILES}

# We don't have suitable infrastructure in pkgsrc for generating frontend
# assets, so we'll extract prebuilt frontend assets.
FE_DISTNAME=			${DISTNAME}.linux-amd64.tar.gz
DISTFILES+=			${FE_DISTNAME}
SITES.${FE_DISTNAME}=		https://dl.grafana.com/oss/release/
EXTRACT_DIR.${FE_DISTNAME}=	${WRKDIR}/linux

GO_DIST_BASE=		${DISTNAME}
GO_SRCPATH=		github.com/grafana/grafana

#BUILD_DEPENDS+=	yarn>=1.15.0:../../devel/yarn

CHECK_PORTABILITY_SKIP=		packaging/rpm/control/postinst

CHECK_RELRO_SKIP+=		bin/grafana-cli
CHECK_RELRO_SKIP+=		bin/grafana-server

USE_TOOLS+=			pax

PUBLICDIR=	${PREFIX}/share/grafana/public
DATADIR=	${VARBASE}/lib/grafana/data
PLUGINDIR=	${VARBASE}/lib/grafana/plugins
LOGDIR=		${VARBASE}/log/grafana

SUBST_CLASSES+=		fix-cfg
SUBST_STAGE.fix-cfg=	pre-configure
SUBST_MESSAGE.fix-cfg=	Adding pkgsrc paths in sample config
SUBST_FILES.fix-cfg=	conf/sample.ini
SUBST_SED.fix-cfg=	-e 's,^;\(data = \).*,\1${DATADIR},g'
SUBST_SED.fix-cfg+=	-e 's,^;\(logs = \).*,\1${LOGDIR},g'
SUBST_SED.fix-cfg+=	-e 's,^;\(plugins = \).*,\1${PLUGINDIR},g'
SUBST_SED.fix-cfg+=	-e 's,^;\(static_root_path = \).*,\1${PUBLICDIR},g'

BUILD_DEFS+=		GRAFANA_USER GRAFANA_GROUP VARBASE
FILES_SUBST+=		GRAFANA_USER=${GRAFANA_USER:Q}
FILES_SUBST+=		GRAFANA_GROUP=${GRAFANA_GROUP:Q}
FILES_SUBST+=		DATADIR=${DATADIR:Q}

.include "../../lang/go/go-vars.mk"
.include "../../mk/bsd.prefs.mk"

GRAFANA_USER?=		grafana
GRAFANA_GROUP?=		grafana
OWN_DIRS_PERMS+=	${DATADIR} ${GRAFANA_USER} ${GRAFANA_GROUP} 0700
OWN_DIRS_PERMS+=	${LOGDIR} ${GRAFANA_USER} ${GRAFANA_GROUP} 0700
OWN_DIRS_PERMS+=	${PLUGINDIR} ${GRAFANA_USER} ${GRAFANA_GROUP} 0700
PKG_USERS_VARS+=	GRAFANA_USER
PKG_GROUPS_VARS+=	GRAFANA_GROUP
PKG_GROUPS=		${GRAFANA_GROUP}
PKG_USERS=		${GRAFANA_USER}:${GRAFANA_GROUP}
RCD_SCRIPTS=		grafana

INSTALLATION_DIRS+=	bin
INSTALLATION_DIRS+=	share/examples/grafana
INSTALLATION_DIRS+=	share/grafana/public

CONF_FILES+=	${PREFIX}/share/grafana/conf/sample.ini \
		${PKG_SYSCONFDIR}/grafana.conf

pre-patch:
	${RM} -rf ${WRKSRC}/vendor/golang.org/x/xerrors

#post-build:
#	cd ${WRKSRC} && yarn install --pure-lockfile && yarn build

do-install:
	cd ${WRKDIR} && ${PAX} -rw bin ${DESTDIR}${PREFIX}
	cd ${WRKDIR}/linux/${DISTNAME}/public && \
		${PAX} -rw . ${DESTDIR}${PUBLICDIR}
	cd ${WRKSRC} && ${PAX} -rw conf \
		${DESTDIR}${PREFIX}/share/grafana/

.include "../../devel/go-xerrors/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
