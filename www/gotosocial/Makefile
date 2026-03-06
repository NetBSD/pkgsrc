# $NetBSD: Makefile,v 1.57 2026/03/06 21:08:07 bsiegert Exp $

DISTNAME=	gotosocial-0.19.0
PKGREVISION=	8
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=superseriousbusiness/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://gotosocial.org/
COMMENT=	Fediverse server written in Go
LICENSE=	gnu-agpl-v3

# TODO: fix build of this package with Go 1.25 and remove this line
GO_VERSION_DEFAULT=	124

USE_TOOLS+=	pax tar

ASSETS=		${DISTNAME:S/-/_/}_web-assets.tar.gz
DISTFILES:=	${DEFAULT_DISTFILES} ${ASSETS}
EXTRACT_ONLY=	${DISTFILES}

SITES.${ASSETS}=	${MASTER_SITES:=${GITHUB_PROJECT}/releases/download/${GITHUB_TAG}/}

MAKE_ENV+=	VERSION=${PKGVERSION_NOREV}
BUILD_DEFS+=	VARBASE

.include "go-modules.mk"

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

post-install:
	${MKDIR} ${DESTDIR}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/example/config.yaml ${DESTDIR}/${EGDIR}/config.yaml
	${INSTALL_DATA} ${WRKSRC}/example/docker-compose/docker-compose.yaml ${DESTDIR}/${EGDIR}/docker-compose.yaml
	${INSTALL_DATA} ${WRKSRC}/example/gotosocial.service ${DESTDIR}/${EGDIR}/gotosocial.service
	# Installs the assets source, may not be necessary
	cd ${WRKSRC} && ${PAX} -rw web ${DESTDIR}/${EGDIR}
	cd ${WRKDIR} && ${PAX} -rw web ${DESTDIR}/${EGDIR}
	# do not install extra binaries
	# TOOD: check if they are wanted
	cd ${DESTDIR}${PREFIX}/bin && ${RM} gen gen-ulid process-emoji process-media

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
