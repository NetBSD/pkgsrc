# $NetBSD: Makefile,v 1.3 2017/07/23 07:20:42 wiz Exp $

GITHUB_PROJECT=	grafana
DISTNAME=	grafana-4.4.1
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=grafana/}
EXTRACT_SUFX=	.tar.gz

MAINTAINER=	tnn@NetBSD.org
HOMEPAGE=	https://grafana.com/
COMMENT=	Metrics dashboard and graph editor
LICENSE=	apache-2.0

GR_DISTNAME=			${DISTNAME}${EXTRACT_SUFX}
DISTFILES=			${GR_DISTNAME}
EXTRACT_ONLY=			${GR_DISTNAME}
EXTRACT_DIR.${GR_DISTNAME}=	${WRKDIR}/src/github.com/grafana
WRKSRC=				${WRKDIR}/src/github.com/grafana/grafana

# We don't have suitable infrastructure in pkgsrc for generating frontend
# assets, so we'll extract prebuilt frontend assets.
FE_DISTNAME=			${DISTNAME}.linux-x64${EXTRACT_SUFX}
SITES.${FE_DISTNAME}=		https://s3-us-west-2.amazonaws.com/grafana-releases/release/
DISTFILES+=			${FE_DISTNAME}
EXTRACT_ONLY+=			${FE_DISTNAME}
EXTRACT_DIR.${FE_DISTNAME}=	${WRKDIR}/frontend_assets

BUILD_DEPENDS+=			go-[0-9]*:../../lang/go

CHECK_PORTABILITY_SKIP=		packaging/rpm/control/postinst

CHECK_RELRO_SKIP+=		bin/grafana-cli
CHECK_RELRO_SKIP+=		bin/grafana-server

PKGSRC_MAKE_ENV+=		GOPATH=${WRKDIR}
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

INSTALLATION_DIRS+=	bin share/examples/grafana share/grafana/conf	\
			  share/grafana/public

CONF_FILES+=	${PREFIX}/share/grafana/conf/sample.ini		\
		  ${PKG_SYSCONFDIR}/grafana.conf

post-extract:
	${MV} ${WRKDIR}/src/github.com/grafana/${DISTNAME}	\
	  ${WRKDIR}/src/github.com/grafana/grafana

do-build:
.for b in grafana-server grafana-cli
	cd ${WRKSRC} && ${SETENV} ${PKGSRC_MAKE_ENV}		\
	  ${PREFIX}/bin/go build -ldflags "-w -X main.version=${PKGVERSION_NOREV} -X main.commit=${GITHUB_TAG} -X main.buildstamp=pkgsrc"	\
	  -o ./bin/${b} ./pkg/cmd/${b}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/grafana-server		\
	  ${DESTDIR}${PREFIX}/bin/grafana-server
	${INSTALL_PROGRAM} ${WRKSRC}//bin/grafana-cli		\
	  ${DESTDIR}${PREFIX}/bin/grafana-cli
	cd ${WRKDIR}/frontend_assets/${DISTNAME}/public &&	\
	  ${PAX} -rw . ${DESTDIR}${PUBLICDIR}
	${INSTALL_DATA} ${WRKSRC}/conf/defaults.ini		\
	  ${DESTDIR}${PREFIX}/share/grafana/conf/defaults.ini
	${INSTALL_DATA} ${WRKSRC}/conf/sample.ini		\
	  ${DESTDIR}${PREFIX}/share/grafana/conf/sample.ini

.include "../../mk/bsd.pkg.mk"
