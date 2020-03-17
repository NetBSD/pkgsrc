# $NetBSD: Makefile,v 1.27 2020/03/17 13:08:38 nia Exp $

DISTNAME=	gitea-1.11.3
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-gitea/}
CATEGORIES=	www
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	tuxillo@quantumachine.net
HOMEPAGE=	https://gitea.io/
COMMENT=	Compact self-hosted Git service
LICENSE=	mit

GO_DIST_BASE=		${DISTNAME}
GO_SRCPATH=		code.gitea.io/gitea

.include "../../lang/go/go-vars.mk"
.include "options.mk"

.if !empty(GO_TAGS)
GO_BUILD_PATTERN+=	-tags "${GO_TAGS}"
.endif

GO_BUILD_PATTERN+=	${GO_SRCPATH}

BUILD_DEFS+=	VARBASE GITEA_USER GITEA_GROUP

EXTRACT_USING=	bsdtar
USE_TOOLS+=	pax
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

SUBST_CLASSES+=			fix-version
SUBST_STAGE.fix-version=	pre-configure
SUBST_MESSAGE.fix-version=	Fix the version number.
SUBST_FILES.fix-version=	${WRKSRC}/main.go
SUBST_SED.fix-version=		-E 's\#^(var Version = )"[^"]+"\#\1"${PKGVERSION}"\#'

SUBST_CLASSES+=		fix-var
SUBST_STAGE.fix-var=	pre-configure
SUBST_MESSAGE.fix-var=	Replace some vars
SUBST_FILES.fix-var=	${WRKDIR}/app.ini.sample
SUBST_VARS.fix-var=	VARBASE GITEA_USER

MAKE_DIRS+=	${PKG_SYSCONFDIR}/conf

CONF_FILES_PERMS+=	${EGDIR}/app.ini.sample ${PKG_SYSCONFDIR}/conf/app.ini \
			${GITEA_USER} ${GITEA_GROUP} 0600

FILES_SUBST+=	GITEA_USER=${GITEA_USER}
FILES_SUBST+=	GITEA_GROUP=${GITEA_GROUP}
FILES_SUBST+=	GITEA_USER_HOME=${VARBASE}/db/gitea
FILES_SUBST+=	GITEA_SHARE_DIR=${PREFIX}/share/gitea

RCD_SCRIPTS+=	gitea

pre-patch:
	${CP} ${FILESDIR}/app.ini.sample ${WRKDIR}/

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/bin/gitea ${DESTDIR}${PREFIX}/sbin
	cd ${WRKSRC}/options && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/gitea/options/
	cd ${WRKSRC}/templates && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/gitea/templates/
	cd ${WRKSRC}/public && ${PAX} -rw -pp . ${DESTDIR}${PREFIX}/share/gitea/public/

post-install:
	${INSTALL_DATA} ${WRKDIR}/app.ini.sample ${DESTDIR}${EGDIR}

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
