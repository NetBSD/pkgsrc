# $NetBSD: Makefile,v 1.10 2009/08/29 15:37:47 wiz Exp $
#

DISTNAME=		libdrm-2.4.13
CATEGORIES=		x11 graphics
MASTER_SITES=		http://dri.freedesktop.org/libdrm/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		joerg@NetBSD.org
HOMEPAGE=		http://dri.freedesktop.org/wiki/DRM
COMMENT=		Userspace interface to kernel DRM services

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		pkg-config
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	libdrm.pc.in
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

ATOMIC_OPS_CHECK?=	0

SUBST_CLASSES+=		atomic
SUBST_FILES.atomic=	libdrm/xf86drm.h
SUBST_MESSAGE.atomic=	Configuring xf86drm.h's atomic operations.
SUBST_STAGE.atomic=	pre-configure
SUBST_VARS.atomic=	ATOMIC_OPS_CHECK

.if ${OPSYS} == "NetBSD" && !target(netbsd-atomic-ops-check)
netbsd-atomic-ops-check:
ATOMIC_OPS_CHECK!=\
  if ( ${NM} /usr/lib/libc.so | ${GREP} -q atomic_cas_uint ); then	\
    ${ECHO} "1";	\
  else	\
    ${ECHO} "0";	\
  fi
.endif

CONFIGURE_ARGS+=	PTHREADSTUBS_CFLAGS=-I${PREFIX}/include \
			PTHREADSTUBS_LIBS=-L${PREFIX}/lib

.include "../../mk/bsd.pkg.mk"
