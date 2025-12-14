# $NetBSD: Makefile,v 1.8 2025/12/14 10:17:57 vins Exp $

DISTNAME=	xtrlock-2.18
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/x/xtrlock/}
EXTRACT_SUFX=	.tar.xz
DISTFILES=	${DEFAULT_DISTFILES:S/-/_/}

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://salsa.debian.org/debian/xtrlock
COMMENT=	Simple X11 screen lock tool
LICENSE=	gnu-gpl-v3

USE_IMAKE=	yes

FORCE_C_STD=	c99

.include "../../mk/bsd.prefs.mk"

# mitigate CVE-2016-10894
CFLAGS+=	-DMULTITOUCH
.if exists(/etc/shadow) && !(${OPSYS:M*BSD} != "" || ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly")
CFLAGS+=	-DSHADOW_PWD    #getspnam()
.endif

LDFLAGS+=	-lXi

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
SUBST_CLASSES+=		defs
SUBST_STAGE.defs=	post-configure
SUBST_FILES.defs+=	Makefile
SUBST_SED.defs=		-e 's|-D_BSD_SOURCE[[:space:]]*-D_SVID_SOURCE|-D_DEFAULT_SOURCE|g'
SUBST_MESSAGE.defs=	Replacing deprecated preprocessor-defined macros.
.endif

MAKE_FLAGS+=		CCOPTIONS=${CFLAGS:Q}
MAKE_FLAGS+=		LOCAL_LDFLAGS=${LDFLAGS:Q}
MAKE_FLAGS+=		MANDIR=${PREFIX}/${PKGMANDIR}/man1

.if	${OPSYS} == "Linux"
SETUID_ROOT_PERMS?=	${REAL_ROOT_USER} shadow 2555
.elif ${OPSYS} == "OpenBSD"
SETUID_ROOT_PERMS?=	${REAL_ROOT_USER} _shadow 2555
.else
SETUID_ROOT_PERMS?=	${REAL_ROOT_USER} ${BINGRP} 4555
.endif
SPECIAL_PERMS+=		bin/xtrlock ${SETUID_ROOT_PERMS}

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
