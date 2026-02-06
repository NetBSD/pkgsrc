# $NetBSD: Makefile,v 1.4 2026/02/06 10:06:20 wiz Exp $

DISTNAME=	sddm-0.21.0
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=sddm/}
GITHUB_TAG=	refs/tags/v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/sddm/sddm
COMMENT=	QML-based X11 and Wayland display manager
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3

WRKSRC=		${WRKDIR}/${DISTNAME}

USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++17
USE_TOOLS+=		pkg-config

.if !exists(/etc/login.defs)
CMAKE_CONFIGURE_ARGS+=	-DUID_MIN=1000
CMAKE_CONFIGURE_ARGS+=	-DUID_MAX=65000
.endif
CMAKE_CONFIGURE_ARGS+=	-DDBUS_CONFIG_DIR=${PREFIX}/share/examples/sddm
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_SYSCONFDIR:PATH=${PKG_SYSCONFDIR:Q}
CMAKE_CONFIGURE_ARGS+=	-DBUILD_MAN_PAGES=ON
CMAKE_CONFIGURE_ARGS+=	-DRST2MAN_EXECUTABLE=${PREFIX}/bin/rst2man-${PYVERSSUFFIX}

TOOL_DEPENDS+=	extra-cmake-modules-[0-9]*:../../devel/extra-cmake-modules
TOOL_DEPENDS+=	${PYPKGPREFIX}-docutils-[0-9]*:../../textproc/py-docutils

.include "options.mk"
.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Linux"
CMAKE_CONFIGURE_ARGS+=	-DENABLE_JOURNALD=OFF
CMAKE_CONFIGURE_ARGS+=	-DNO_SYSTEMD=ON
.endif

.if ${OPSYS} == "NetBSD"
CMAKE_CONFIGURE_ARGS+=	-DSDDM_INITIAL_VT=5
.endif

.if ${OPSYS} == "FreeBSD"
CMAKE_CONFIGURE_ARGS+=	-DSDDM_INITIAL_VT=7
.endif

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	pre-configure
SUBST_MESSAGE.vars=	Fix hard-coded absolute paths.
SUBST_FILES.vars=	src/common/Configuration.h
SUBST_FILES.vars+=	data/man/sddm.conf.rst.in
SUBST_VARS.vars=	PREFIX X11BASE

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Set path to sddm executable.
SUBST_FILES.paths=	../xinitrc.desktop
SUBST_VARS.paths=	PREFIX

BUILD_DEFS+=		VARBASE
SDDM_GROUP=		sddm
SDDM_USER=		sddm
SDDM_HOME=		${VARBASE}/lib/sddm
PKG_GROUPS_VARS+=	SDDM_GROUP
PKG_USERS_VARS+=	SDDM_USER
PKG_GROUPS=		${SDDM_GROUP}
PKG_USERS=		${SDDM_USER}:${SDDM_GROUP}
PKG_GECOS.${SDDM_USER}=	SDDM user
PKG_HOME.${SDDM_USER}=	${SDDM_HOME}

FILES_SUBST+=	SDDM_USER=${SDDM_USER}
FILES_SUBST+=	SDDM_GROUP=${SDDM_GROUP}

OWN_DIRS_PERMS+=	${SDDM_HOME} ${SDDM_USER} ${SDDM_GROUP} 0770

.if ${INIT_SYSTEM} == "rc.d"
DEPENDS+=	daemonize-[0-9]*:../../sysutils/daemonize
RCD_SCRIPTS+=	sddm
.endif

INSTALLATION_DIRS+=	share/xsessions

post-extract:
	${CP} ${FILESDIR}/xsessions/xinitrc.desktop ${WRKDIR}/xinitrc.desktop

post-install:
	${INSTALL_DATA} ${FILESDIR}/xsessions/ctwm.desktop ${DESTDIR}${PREFIX}/share/xsessions/ctwm.desktop
	${INSTALL_DATA} ${WRKDIR}/xinitrc.desktop ${DESTDIR}${PREFIX}/share/xsessions/xinitrc.desktop
	${INSTALL_SCRIPT} ${FILESDIR}/xinit-session ${DESTDIR}${PREFIX}/share/sddm/scripts/xinit-session

PYTHON_FOR_BUILD_ONLY=  yes
.include "../../devel/cmake/build.mk"
.include "../../lang/python/pyversion.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../x11/libxcb/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
