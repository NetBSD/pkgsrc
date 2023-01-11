# $NetBSD: Makefile,v 1.5 2023/01/11 17:28:38 bsiegert Exp $

DISTNAME=	gotosocial-0.6.0-source-code
PKGNAME=	${DISTNAME:S/-source-code//}
PKGREVISION=	3
MASTER_SITES=	${MASTER_SITE_GITHUB:=superseriousbusiness/}
GITHUB_RELEASE=	v0.6.0
GITHUB_PROJECT=	gotosocial
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/superseriousbusiness/gotosocial/
COMMENT=	Fediverse server written in Go
LICENSE=	gnu-agpl-v3
USE_TOOLS+=	pax

# release archive has no toplevel folder.
EXTRACT_DIR=	${WRKDIR}/${PKGNAME}
WRKSRC=		${EXTRACT_DIR}

MAKE_ENV+=	VERSION=${PKGVERSION_NOREV}
#MAKE_ENV+=	COMMIT=""
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
SUBST_STAGE.cfg=	pre-configure
SUBST_FILES.cfg=	example/config.yaml
SUBST_SED.cfg=		-e 's,./web/template/,${GOTOSOCIAL_DATA}/template/,g'
SUBST_SED.cfg+=		-e 's,./web/assets/,${GOTOSOCIAL_DATA}/assets/,g'
SUBST_SED.cfg+=		-e 's,./gotosocial/storage,"${GOTOSOCIAL_DB}/storage,g'

# restricted to amd64:
# https://gitlab.com/cznic/libc/-/issues/15
# https://gitlab.com/cznic/libc/-/issues/12
# https://gitlab.com/cznic/libc/-/issues/11
# on FreeBSD, the modernc.org/* packages do not work on arm64:
# "imports modernc.org/libc/errno: build constraints exclude all Go files in /usr/ports/net-im/gotosocial/work/gotosocial-0.5.2/vendor/modernc.org/libc/errno"
ONLY_FOR_PLATFORM=	*-*-x86_64

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} scripts/build.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gotosocial ${DESTDIR}/${PREFIX}/bin/
	${MKDIR} ${DESTDIR}/${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/example/config.yaml ${DESTDIR}/${EGDIR}/config.yaml
	${INSTALL_DATA} ${WRKSRC}/example/docker-compose/docker-compose.yaml ${DESTDIR}/${EGDIR}/docker-compose.yaml
	${INSTALL_DATA} ${WRKSRC}/example/gotosocial.service ${DESTDIR}/${EGDIR}/gotosocial.service
	cd ${WRKSRC} && ${PAX} -rw web ${DESTDIR}/${EGDIR}

do-test:
	cd ${WRKSRC} && ./gotosocial --version

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
