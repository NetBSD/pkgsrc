# $NetBSD: Makefile,v 1.7 2004/10/20 14:33:30 reed Exp $

DISTNAME=		${DISTFILES}
PKGNAME=		xorg-clients-${XORG_VER}
PKGREVISION=		3
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_XORG}
DISTFILES=		X11R${XORG_VER}-src1.tar.gz \
			X11R${XORG_VER}-src2.tar.gz \
			X11R${XORG_VER}-src3.tar.gz

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://www.x.org/
COMMENT=		X.org client programs and related files

USE_X11=		yes
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
DISTINFO_FILE=		${.CURDIR}/../../x11/xorg-libs/distinfo
PATCHDIR=		${.CURDIR}/../../x11/xorg-libs/patches

XBUILD_DIRS=		lib/xtrans lib/lbxutil programs fonts/util
XINSTALL_DIRS=		programs fonts/util
XINSTALL_MAN_DIRS=	programs

# XXX todo: define build's VarDirectory to pkgsrc's VARBASE
OWN_DIRS=               ${VARBASE}/lib/xdm
OWN_DIRS_PERMS+=        ${VARBASE}/lib/xdm/authdir ${ROOT_USER} ${ROOT_GROUP} 0700
OWN_DIRS_PERMS+=        ${VARBASE}/lib/xdm/authdir/authfiles ${ROOT_USER} ${ROOT_GROUP} 0700

EGDIR=			${LOCALBASE}/share/examples/xorg/xdm
PKG_SYSCONFSUBDIR=	xorg/xdm
CONF_FILES=		${EGDIR}/xdm/xdm-config ${PKG_SYSCONFDIR}/xdm-config
CONF_FILES+=		${EGDIR}/xdm/Xservers ${PKG_SYSCONFDIR}/Xservers
CONF_FILES+=		${EGDIR}/xdm/Xresources ${PKG_SYSCONFDIR}/Xresources
CONF_FILES+=		${EGDIR}/xdm/Xaccess ${PKG_SYSCONFDIR}/Xaccess
CONF_FILES_PERMS=	${EGDIR}/xdm/Xsetup_0 ${PKG_SYSCONFDIR}/Xsetup_0 ${ROOT_USER} ${ROOT_GROUP} 0755
CONF_FILES_PERMS+=	${EGDIR}/xdm/Xsession ${PKG_SYSCONFDIR}/Xsession ${ROOT_USER} ${ROOT_GROUP} 0755
CONF_FILES_PERMS+=	${EGDIR}/xdm/TakeConsole ${PKG_SYSCONFDIR}/TakeConsole ${ROOT_USER} ${ROOT_GROUP} 0755
CONF_FILES_PERMS+=	${EGDIR}/xdm/GiveConsole ${PKG_SYSCONFDIR}/GiveConsole ${ROOT_USER} ${ROOT_GROUP} 0755
CONF_FILES_PERMS+=	${EGDIR}/xdm/Xwilling ${PKG_SYSCONFDIR}/Xwilling ${ROOT_USER} ${ROOT_GROUP} 0755

post-buildlink:
	@${MKDIR} ${WRKSRC}/exports/include
	@${CP} ${X11ROOT}/include/X11/fonts/*.h ${BUILDLINK_DIR}/include

post-configure:
	@${MKDIR} ${WRKSRC}/exports/lib
	@${CP} ${X11ROOT}/lib/lib* ${WRKSRC}/exports/lib

post-install:
	@${CHMOD} a+r ${X11ROOT}/bin/xterm

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.  include "../../security/PAM/buildlink3.mk"
.endif

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../meta-pkgs/xorg/Makefile.common"
.include "../../x11/Xrandr/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
