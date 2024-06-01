# $NetBSD: Makefile,v 1.35 2024/06/01 14:03:05 bsiegert Exp $

DISTNAME=	gotosocial-0.15.0-source-code
PKGNAME=	${DISTNAME:S/-source-code//}
PKGREVISION=	2
CATEGORIES=	www

MAINTAINER=	nikita@NetBSD.org
HOMEPAGE=	https://github.com/superseriousbusiness/gotosocial/
COMMENT=	Fediverse server written in Go
LICENSE=	gnu-agpl-v3
USE_TOOLS+=	pax tar

DISTFILES=      gotosocial-0.15.0-source-code.tar.gz
DISTFILES+=	gotosocial_0.15.0_web-assets.tar.gz

SITES.gotosocial-0.15.0-source-code.tar.gz= \
	-https://github.com/superseriousbusiness/gotosocial/releases/download/v0.15.0/gotosocial-0.15.0-source-code.tar.gz

SITES.gotosocial_0.15.0_web-assets.tar.gz= \
	-https://github.com/superseriousbusiness/gotosocial/releases/download/v0.15.0/gotosocial_0.15.0_web-assets.tar.gz

# release archive has no toplevel folder.
EXTRACT_DIR=	${WRKDIR}/${PKGNAME}
WRKSRC=		${EXTRACT_DIR}

MAKE_ENV+=	VERSION=${PKGVERSION_NOREV}
BUILD_DEFS+=	VARBASE

.include "../../mk/bsd.prefs.mk"

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

# restricted to amd64:
# https://gitlab.com/cznic/libc/-/issues/15
# https://gitlab.com/cznic/libc/-/issues/12
# https://gitlab.com/cznic/libc/-/issues/11
# https://github.com/superseriousbusiness/gotosocial/issues/1753
# on FreeBSD, the modernc.org/* packages do not work on arm64:
# "imports modernc.org/libc/errno: build constraints exclude all Go files in /usr/ports/net-im/gotosocial/work/gotosocial-0.5.2/vendor/modernc.org/libc/errno"
# BUG: does not build on Sun
ONLY_FOR_PLATFORM=	*-*-x86_64

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} scripts/build.sh
	# cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} && \
	# go build -o gotosocial ./cmd/gotosocial

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gotosocial ${DESTDIR}/${PREFIX}/bin/
	${MKDIR} ${DESTDIR}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/example/config.yaml ${DESTDIR}/${EGDIR}/config.yaml
	${INSTALL_DATA} ${WRKSRC}/example/docker-compose/docker-compose.yaml ${DESTDIR}/${EGDIR}/docker-compose.yaml
	${INSTALL_DATA} ${WRKSRC}/example/gotosocial.service ${DESTDIR}/${EGDIR}/gotosocial.service
	cd ${WRKSRC} && ${TAR} -xzf ${DISTDIR}/gotosocial_0.15.0_web-assets.tar.gz
	cd ${WRKSRC} && ${PAX} -rw web ${DESTDIR}/${EGDIR}

do-test:
	cd ${WRKSRC} && ./gotosocial --version

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
