# $NetBSD: Makefile,v 1.36 2020/06/02 08:24:57 adam Exp $

DISTNAME=	gitea-1.11.5
PKGREVISION=	2
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-gitea/}
CATEGORIES=	www
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tuxillo@quantumachine.net
HOMEPAGE=	https://gitea.io/
COMMENT=	Compact self-hosted Git service
LICENSE=	mit

GO_DIST_BASE=		${DISTNAME}
GO_SRCPATH=		code.gitea.io/gitea

FRONTEND=		${DISTNAME}-frontend.tar.gz
SITES.${FRONTEND}=	${MASTER_SITE_LOCAL}
DISTFILES:=		${DEFAULT_DISTFILES} ${FRONTEND}

BUILD_TARGET=	backend

#
# When updating this package it is necessary to build the front-end artefacts
# and upload them to LOCAL_PORTS.  Doing this at build time is untenable as npm
# will download a significant number of modules.
#
# Install nodejs>=10 and npm, uncomment the additional BUILD_TARGET, run the
# generate-artefacts target, then upload the distfile to LOCAL_PORTS.
#
#BUILD_TARGET+=	frontend
#

.include "../../lang/go/go-vars.mk"
.include "options.mk"

BUILD_DEFS+=	VARBASE GITEA_USER GITEA_GROUP

EXTRACT_USING=	bsdtar
USE_TOOLS+=	ggrep gmake pax tar
DEPENDS+=	git-base-[0-9]*:../../devel/git-base

EGDIR=		${PREFIX}/share/examples/gitea

OWN_DIRS_PERMS+=	${VARBASE}/log/gitea ${GITEA_USER} ${GITEA_GROUP} 0755
OWN_DIRS_PERMS+=	${VARBASE}/db/gitea ${GITEA_USER} ${GITEA_GROUP} 0755
OWN_DIRS_PERMS+=	${PKG_SYSCONFDIR}/conf ${GITEA_USER} ${GITEA_GROUP} 0755

GITEA_USER?=	git
GITEA_GROUP?=	git

PKG_GROUPS_VARS+=	GITEA_GROUP
PKG_USERS_VARS+=	GITEA_USER

PKG_SYSCONFSUBDIR=	gitea

INSTALLATION_DIRS+=	sbin share/gitea share/examples/gitea

PKG_GROUPS=	${GITEA_GROUP}
PKG_USERS=	${GITEA_USER}:${GITEA_GROUP}

PKG_SHELL.${GITEA_USER}=	${SH}
PKG_HOME.${GITEA_USER}=		${VARBASE}/db/gitea

SUBST_CLASSES+=		fix-var
SUBST_STAGE.fix-var=	pre-configure
SUBST_MESSAGE.fix-var=	Replace some vars
SUBST_FILES.fix-var=	${WRKDIR}/app.ini.sample
SUBST_VARS.fix-var=	VARBASE GITEA_USER

CONF_FILES_PERMS+=	${EGDIR}/app.ini.sample ${PKG_SYSCONFDIR}/conf/app.ini \
			${GITEA_USER} ${GITEA_GROUP} 0600

FILES_SUBST+=	GITEA_USER=${GITEA_USER}
FILES_SUBST+=	GITEA_GROUP=${GITEA_GROUP}
FILES_SUBST+=	GITEA_USER_HOME=${VARBASE}/db/gitea
FILES_SUBST+=	GITEA_SHARE_DIR=${PREFIX}/share/gitea

RCD_SCRIPTS+=	gitea

MAKE_ENV+=	TAGS="${GO_TAGS}"

pre-patch:
	${CP} ${FILESDIR}/app.ini.sample ${WRKDIR}/
	${CP} ${WRKDIR}/${DISTNAME}/.eslint* ${WRKSRC}/
	${CP} ${WRKDIR}/${DISTNAME}/.stylelintrc ${WRKSRC}/
	${ECHO} ${PKGVERSION_NOREV} > ${WRKSRC}/VERSION

do-build:
	cd ${WRKSRC} && ${BUILD_MAKE_CMD} ${BUILD_TARGET}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gitea ${DESTDIR}${PREFIX}/sbin
	cd ${WRKSRC}/options && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/gitea/options/
	cd ${WRKSRC}/templates && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/gitea/templates/
	cd ${WRKSRC}/public && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/gitea/public/
	cd ${WRKDIR}/public && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/gitea/public/
	${CHMOD} -R g-w ${DESTDIR}${PREFIX}/share/gitea
	${CHMOD} -x ${DESTDIR}${PREFIX}/share/gitea/public/vendor/plugins/tribute/tribute.css
	${CHMOD} -x ${DESTDIR}${PREFIX}/share/gitea/public/vendor/plugins/tribute/tribute.min.js

post-install:
	${INSTALL_DATA} ${WRKDIR}/app.ini.sample ${DESTDIR}${EGDIR}

.PHONY: generate-frontend
generate-frontend: build
	cd ${WRKSRC} && ${TAR} -zcf ${WRKDIR}/${PKGNAME_NOREV}-frontend.tar.gz public/css public/js
	@${ECHO} "Now upload ${WRKDIR}/${PKGNAME_NOREV}-frontend.tar.gz to LOCAL_PORTS"

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
