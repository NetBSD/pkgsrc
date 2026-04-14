# $NetBSD: Makefile,v 1.1 2026/04/14 13:27:07 kikadf Exp $

DISTNAME=	swaylock-1.8.5
CATEGORIES=	wayland
MASTER_SITES=	${MASTER_SITE_GITHUB:=swaywm/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
HOMEPAGE=	https://swaywm.org/
COMMENT=	Screen locker for Wayland compositors
LICENSE=	mit

USE_TOOLS+=	pkg-config

SUBST_CLASSES+=		nogit
SUBST_STAGE.nogit=	pre-configure
SUBST_MESSAGE.nogit=	Set version
SUBST_FILES.nogit+=	meson.build
SUBST_SED.nogit+=	-e 's/git =/\#git =/g'
SUBST_SED.nogit+=	-e 's/git.found()/false/g'

INSTALLATION_DIRS+=	share/examples/swaylock/pam.d
BUILD_DEFS+=		SYSCONFBASE

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
# needed to read shadow passwords
DEPENDS+=	pam-pwauth_suid-[0-9]*:../../security/pam-pwauth_suid

SUBST_CLASSES+=		pam
SUBST_STAGE.pam=	pre-configure
SUBST_FILES.pam+=	pam/swaylock
SUBST_VARS.pam+=	PREFIX

post-extract:
	${CP} -f ${FILESDIR}/swaylock ${WRKSRC}/pam/swaylock

.endif

CONF_FILES+=	${PREFIX}/share/examples/swaylock/pam.d/swaylock \
		${SYSCONFBASE}/pam.d/swaylock

post-install:
	${MV} ${DESTDIR}${PKG_SYSCONFDIR}/pam.d/swaylock \
		${DESTDIR}${PREFIX}/share/examples/swaylock/pam.d/

.include "../../devel/meson/build.mk"
.include "../../devel/wayland/buildlink3.mk"
.include "../../devel/wayland-protocols/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../textproc/scdoc/tool.mk"
.include "../../x11/libxkbcommon/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
