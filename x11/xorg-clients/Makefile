# $NetBSD: Makefile,v 1.16 2005/06/17 04:49:49 jlam Exp $

DISTNAME=	${DISTFILES}
PKGNAME=	xorg-clients-${XORG_VER}
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG}
DISTFILES=	X11R${XORG_VER}-src1.tar.gz \
		X11R${XORG_VER}-src2.tar.gz \
		X11R${XORG_VER}-src3.tar.gz

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.x.org/
COMMENT=	X.org client programs and related files

USE_PKGINSTALL=		yes
DISTINFO_FILE=		${.CURDIR}/../../x11/xorg-libs/distinfo
PATCHDIR=		${.CURDIR}/../../x11/xorg-libs/patches

XBUILD_DIRS=		lib/xtrans lib/lbxutil programs fonts/util
XINSTALL_DIRS=		programs fonts/util
XINSTALL_MAN_DIRS=	programs

# XXX todo: define build's VarDirectory to pkgsrc's VARBASE
OWN_DIRS=               ${VARBASE}/lib/xdm
OWN_DIRS_PERMS+=        ${VARBASE}/lib/xdm/authdir \
	${ROOT_USER} ${ROOT_GROUP} 0700
OWN_DIRS_PERMS+=        ${VARBASE}/lib/xdm/authdir/authfiles \
	${ROOT_USER} ${ROOT_GROUP} 0700

EGDIR=			${PREFIX}/share/examples/xorg/xdm
PKG_SYSCONFSUBDIR=	xorg/xdm

CONF_FILES=		${EGDIR}/xdm-config ${PKG_SYSCONFDIR}/xdm-config
CONF_FILES+=		${EGDIR}/Xservers ${PKG_SYSCONFDIR}/Xservers
CONF_FILES+=		${EGDIR}/Xresources ${PKG_SYSCONFDIR}/Xresources
CONF_FILES+=		${EGDIR}/Xaccess ${PKG_SYSCONFDIR}/Xaccess
CONF_FILES_PERMS=	${EGDIR}/Xsetup_0 ${PKG_SYSCONFDIR}/Xsetup_0 \
	${ROOT_USER} ${ROOT_GROUP} 0755
CONF_FILES_PERMS+=	${EGDIR}/Xsession ${PKG_SYSCONFDIR}/Xsession \
	${ROOT_USER} ${ROOT_GROUP} 0755
CONF_FILES_PERMS+=	${EGDIR}/TakeConsole ${PKG_SYSCONFDIR}/TakeConsole \
	${ROOT_USER} ${ROOT_GROUP} 0755
CONF_FILES_PERMS+=	${EGDIR}/GiveConsole ${PKG_SYSCONFDIR}/GiveConsole \
	${ROOT_USER} ${ROOT_GROUP} 0755
CONF_FILES_PERMS+=	${EGDIR}/Xwilling ${PKG_SYSCONFDIR}/Xwilling \
	${ROOT_USER} ${ROOT_GROUP} 0755

post-wrapper:
	@${MKDIR} ${WRKSRC}/exports/include
	@${CP} -p ${X11ROOT}/include/X11/fonts/*.h ${BUILDLINK_DIR}/include

post-configure:
	@${MKDIR} ${WRKSRC}/exports/lib
	@${CP} -p ${X11ROOT}/lib/lib* ${WRKSRC}/exports/lib

post-install:
	@${CHMOD} a+r ${X11ROOT}/bin/xterm

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
.  include "../../security/PAM/buildlink3.mk"
.endif

.include "../../meta-pkgs/xorg/Makefile.common"

.include "../../fonts/Xft2/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../x11/Xrandr/buildlink3.mk"
.include "../../x11/xcursor/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
