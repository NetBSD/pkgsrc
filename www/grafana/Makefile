# $NetBSD: Makefile,v 1.121 2024/06/09 22:44:05 wiz Exp $

DISTNAME=	grafana-11.0.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=grafana/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://grafana.com/
COMMENT=	Metrics dashboard and graph editor
LICENSE=	gnu-agpl-v3 AND apache-2.0 AND mit

DISTFILES=	${DEFAULT_DISTFILES}

# We don't have suitable infrastructure in pkgsrc for generating frontend
# assets, so we'll extract prebuilt frontend assets.
FE_DISTNAME=			${DISTNAME}.linux-amd64.tar.gz
DISTFILES+=			${FE_DISTNAME}
SITES.${FE_DISTNAME}=		https://dl.grafana.com/oss/release/
EXTRACT_DIR.${FE_DISTNAME}=	${WRKDIR}/linux
EXTRACT_ONLY=			${DEFAULT_DISTFILES} ${FE_DISTNAME}

TOOL_DEPENDS+=			go-wire-[0-9]*:../../devel/go-wire

CHECK_PORTABILITY_SKIP=		docs/* packaging/* devenv/*
CHECK_PORTABILITY_SKIP+=	packages/grafana-toolkit/docker/*

USE_TOOLS+=			pax

PUBLICDIR=	${PREFIX}/share/grafana/public
DATADIR=	${VARBASE}/lib/grafana/data
PLUGINDIR=	${VARBASE}/lib/grafana/plugins
LOGDIR=		${VARBASE}/log/grafana

SUBST_CLASSES+=		fix-cfg
SUBST_STAGE.fix-cfg=	pre-configure
SUBST_MESSAGE.fix-cfg=	Adding pkgsrc paths in sample config
SUBST_FILES.fix-cfg=	conf/sample.ini pkg/cmd/grafana-server/commands/flags.go
SUBST_SED.fix-cfg=	-e 's,^;\(data = \).*,\1${DATADIR},g'
SUBST_SED.fix-cfg+=	-e 's,^;\(logs = \).*,\1${LOGDIR},g'
SUBST_SED.fix-cfg+=	-e 's,^;\(plugins = \).*,\1${PLUGINDIR},g'
SUBST_SED.fix-cfg+=	-e 's,^;\(static_root_path = \).*,\1${PUBLICDIR},g'
SUBST_VARS.fix-cfg=	DATADIR PKG_SYSCONFDIR PREFIX

SUBST_CLASSES+=		build
SUBST_STAGE.build=	pre-build
SUBST_MESSAGE.build=	Fixing go path in build.go
SUBST_FILES.build=	pkg/build/cmd.go
SUBST_VARS.build=	GO

BUILD_DEFS+=		GRAFANA_USER GRAFANA_GROUP VARBASE
FILES_SUBST+=		GRAFANA_USER=${GRAFANA_USER:Q}
FILES_SUBST+=		GRAFANA_GROUP=${GRAFANA_GROUP:Q}
FILES_SUBST+=		DATADIR=${DATADIR:Q}

.include "go-modules.mk"

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
INSTALLATION_DIRS+=	share/grafana/public

CONF_FILES+=	${PREFIX}/share/grafana/conf/sample.ini \
		${PKG_SYSCONFDIR}/grafana.conf

post-extract:
	${FIND} ${WRKDIR}/linux -type f -a -exec ${CHMOD} -x "{}" \;

# These comands come from Makefile, build-go target.
do-build:
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${PREFIX}/bin/wire gen -tags oss ./pkg/server ./pkg/cmd/grafana-cli/runner
	cd ${WRKSRC} && ${PKGSRC_SETENV} ${MAKE_ENV} ${GO} run build.go build

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/*/grafana ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/*/grafana-cli ${DESTDIR}${PREFIX}/bin/
	${INSTALL_PROGRAM} ${WRKSRC}/bin/*/grafana-server ${DESTDIR}${PREFIX}/bin/
	cd ${WRKDIR}/linux/grafana-${GITHUB_TAG}/public && \
		${PAX} -rw . ${DESTDIR}${PUBLICDIR}
	cd ${WRKSRC} && ${PAX} -rw conf \
		${DESTDIR}${PREFIX}/share/grafana/
	${RM} ${DESTDIR}${PREFIX}/share/grafana/conf/sample.ini.orig

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
