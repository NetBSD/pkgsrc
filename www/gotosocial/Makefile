# $NetBSD: Makefile,v 1.43 2024/10/21 11:18:34 jperkin Exp $

DISTNAME=	gotosocial-0.17.0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=superseriousbusiness/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/superseriousbusiness/gotosocial/
COMMENT=	Fediverse server written in Go
LICENSE=	gnu-agpl-v3

USE_TOOLS+=	pax tar

# It's not clear that the extra assets tarball is actually necessary, as the
# source code already bundles 99% of the same files.  Verify that the addition
# of "dist/" and "swagger.yaml" are worth the additional download and setup.
ASSETS=		${DISTNAME:S/-/_/}_web-assets.tar.gz
DISTFILES:=	${DEFAULT_DISTFILES} ${ASSETS}
EXTRACT_ONLY=	${DISTFILES}

SITES.${ASSETS}=	${MASTER_SITES:=${GITHUB_PROJECT}/releases/download/${GITHUB_TAG}/}

MAKE_ENV+=	VERSION=${PKGVERSION_NOREV}
BUILD_DEFS+=	VARBASE

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

GOTOSOCIAL_USER?=	gotosocial
GOTOSOCIAL_GROUP?=	gotosocial
GOTOSOCIAL_CHROOT?=	${VARBASE}/chroot/gotosocial
GOTOSOCIAL_DATA?=	${VARBASE}/www/gotosocial
GOTOSOCIAL_DB?=		${VARBASE}/db/gotosocial

PKG_GROUPS+=		${GOTOSOCIAL_GROUP}
PKG_USERS+=		${GOTOSOCIAL_USER}:${GOTOSOCIAL_GROUP}

EGDIR=			${PREFIX}/share/examples/${PKGBASE}
PKG_SYSCONFSUBDIR=	${PKGBASE}

RCD_SCRIPTS=		gotosocial
FILES_SUBST+=		GOTOSOCIAL_CHROOT=${GOTOSOCIAL_CHROOT}
FILES_SUBST+=		GOTOSOCIAL_DATA=${GOTOSOCIAL_DATA}
FILES_SUBST+=		GOTOSOCIAL_DB=${GOTOSOCIAL_DB}
FILES_SUBST+=		GOTOSOCIAL_GROUP=${GOTOSOCIAL_GROUP}
FILES_SUBST+=		GOTOSOCIAL_USER=${GOTOSOCIAL_USER}
FILES_SUBST+=		EGDIR=${EGDIR}

CONF_FILES+=		${EGDIR}/config.yaml ${PKG_SYSCONFDIR}/config.yaml

SUBST_CLASSES+=		cfg
SUBST_MESSAGE.cfg=	Fixing default paths in config
SUBST_STAGE.cfg=	post-configure
SUBST_FILES.cfg=	example/config.yaml
SUBST_SED.cfg=		-e "s,\./web/template/,${GOTOSOCIAL_DATA}/template/,g"
SUBST_SED.cfg+=		-e "s,\./web/assets/,${GOTOSOCIAL_DATA}/assets/,g"
SUBST_SED.cfg+=		-e "s,/gotosocial/storage,${GOTOSOCIAL_DB}/storage,g"

SUBST_CLASSES+=			systemdpaths
SUBST_MESSAGE.systemdpaths=	Fixing paths in systemd file
SUBST_STAGE.systemdpaths=	post-configure
SUBST_FILES.systemdpaths=	example/gotosocial.service
SUBST_SED.systemdpaths=		-e 's,/gotosocial/gotosocial,${PREFIX}/bin/gotosocial,g'
SUBST_SED.systemdpaths+=	-e 's,config.yaml,${PKG_SYSCONFDIR}/config.yaml,g'

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} scripts/build.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gotosocial ${DESTDIR}/${PREFIX}/bin/
	${MKDIR} ${DESTDIR}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/example/config.yaml ${DESTDIR}/${EGDIR}/config.yaml
	${INSTALL_DATA} ${WRKSRC}/example/docker-compose/docker-compose.yaml ${DESTDIR}/${EGDIR}/docker-compose.yaml
	${INSTALL_DATA} ${WRKSRC}/example/gotosocial.service ${DESTDIR}/${EGDIR}/gotosocial.service
	cd ${WRKSRC} && ${PAX} -rw web ${DESTDIR}/${EGDIR}
	cd ${WRKDIR} && ${PAX} -rw web ${DESTDIR}/${EGDIR}

do-test:
	cd ${WRKSRC} && ./gotosocial --version

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
