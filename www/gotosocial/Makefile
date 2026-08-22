# $NetBSD: Makefile,v 1.66 2026/08/22 15:19:18 bsiegert Exp $

DISTNAME=	gotosocial-0.22.1-source-code
PKGNAME=	${DISTNAME:S/-source-code//}
PKGREVISION=	2
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_CODEBERG:=superseriousbusiness/gotosocial/releases/download/v${PKGVERSION_NOREV}/}
SRC_DISTFILE=	gotosocial-${PKGVERSION_NOREV}-source-code.tar.gz
WRKSRC=		${WRKDIR}/gotosocial-${PKGVERSION_NOREV}-source-code

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://gotosocial.org/
COMMENT=	Fediverse server written in Go
LICENSE=	gnu-agpl-v3

USE_TOOLS+=	pax tar

ASSETS=		gotosocial_${PKGVERSION_NOREV}_web-assets.tar.gz
DISTFILES=	${SRC_DISTFILE} ${ASSETS}

EXTRACT_ONLY=	${SRC_DISTFILE} ${ASSETS}
EXTRACT_DIR=	${WRKSRC}

MAKE_ENV+=	VERSION=${PKGVERSION_NOREV}
BUILD_DEFS+=	VARBASE

# Set compilation flags inspired from gotosocial's build.sh
GOFLAGS+=		-trimpath -tags=osusergo,nomsgpack,stdlibjson -ldflags='-s -w -X main.Version=v${PKGVERSION}'
MAKE_ENV+=		CGO_ENABLED=0

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
	${INSTALL_DATA_DIR} ${DESTDIR}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/example/config.yaml ${DESTDIR}/${EGDIR}/config.yaml
	${INSTALL_DATA} ${WRKSRC}/example/docker-compose/docker-compose.yaml ${DESTDIR}/${EGDIR}/docker-compose.yaml
	${INSTALL_DATA} ${WRKSRC}/example/gotosocial.service ${DESTDIR}/${EGDIR}/gotosocial.service
	# Installs the assets source, may not be necessary
	cd ${WRKSRC} && ${PAX} -rw web ${DESTDIR}/${EGDIR}
	# Do not install test/dev binaries
	cd ${DESTDIR}${PREFIX}/bin && ${RM} gen process-emoji process-media

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
