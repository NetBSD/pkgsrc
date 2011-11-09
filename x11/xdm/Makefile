# $NetBSD: Makefile,v 1.16 2011/11/09 18:28:40 cheusov Exp $

DISTNAME=	xdm-1.1.11
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_XORG:=app/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	blair.sadewitz@gmail.com
HOMEPAGE=	http://xorg.freedesktop.org/
COMMENT=	X Display Manager from modular X.org

DEPENDS+=	sessreg-[0-9]*:../../x11/sessreg

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--enable-dynamic-greeter
CONFIGURE_ARGS+=	--enable-tcp-transport
CONFIGURE_ARGS+=	--enable-unix-transport
CONFIGURE_ARGS+=	--enable-xdmshell

USE_TOOLS+=	pkg-config
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

RCD_SCRIPTS=	xdm

BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=	--with-authdir=${VARBASE}/lib/xdm
OWN_DIRS_PERMS+=	${VARBASE}/lib/xdm \
			  ${REAL_ROOT_USER} ${REAL_ROOT_GROUP} 0755

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-[3-4]*)
CFLAGS+=	-fno-strict-aliasing
.endif

.if empty(PKGSRC_COMPILER:Mgcc)
CONFIGURE_ENV+=		ac_cv_path_RAWCPP="cc -E -Uunix -"
.endif

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+=	--with-random-device=/dev/urandom
.endif

# The following forces the X server to start on the 5th virtual terminal.
# This is suboptimal but matches the defaults for the xdm configuration,
# which should work for most installations.  See the definition of
# DEFAULTVT in xsrc/xfree/xc/programs/xdm/config/Imakefile.
#
# If we do not do this, we hit a very annoying and obscure problem: during
# system startup, xdm starts before init spawns gettys.  If the X server
# is started before init spawns the gettys (which easily happens on slow
# machines), it grabs the first virtual terminal (instead of the first
# "free" one).  Later on, when the first getty is started, it grabs the
# same terminal X used (the first one).  As a result, only one of them
# will receive key presses.  And on slow machines, X will have lost access
# to the keyboard.
.if (${OPSYS} == "NetBSD" || ${OPSYS} == "OpenBSD") && \
    (${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64")
CONFIGURE_ARGS+=	--with-default-vt=vt05
.endif

MAKE_FLAGS+=		appdefaultdir=${PREFIX}/lib/X11/app-defaults

.include "options.mk"

.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../mk/pam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
