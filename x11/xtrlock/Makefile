# $NetBSD: Makefile,v 1.3 2023/03/02 15:29:41 vins Exp $

DISTNAME=	xtrlock-2.15
PKGREVISION=	1
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/x/xtrlock/}
EXTRACT_SUFX=	.tar.xz
DISTFILES=	xtrlock_2.15.tar.xz

MAINTAINER=	vins@NetBSD.org
COMMENT=	Simple X11 screen lock tool
LICENSE=	gnu-gpl-v3

# support 'for' loop initial declarations
USE_LANGUAGES=	c99
USE_IMAKE=	yes

# mitigate CVE-2016-10894
CFLAGS+=	-std=c99 -DMULTITOUCH
LDFLAGS+=	-lXi

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
SUBST_CLASSES+=		defs
SUBST_STAGE.defs=	post-configure
SUBST_FILES.defs+=	Makefile
SUBST_SED.defs=		-e 's|-D_BSD_SOURCE[[:space:]]*-D_SVID_SOURCE|-D_DEFAULT_SOURCE|g'
SUBST_MESSAGE.defs=	Replacing deprecated preprocessor-defined macros.
.endif

.if exists(/etc/shadow) && !(${OPSYS:M*BSD} != "" || ${OPSYS} == "Darwin" || ${OPSYS} == "DragonFly")
MAKE_FLAGS+=		CCOPTIONS="${CFLAGS} -DSHADOW_PWD"			#getspnam()
.else
MAKE_FLAGS+=		CCOPTIONS=${CFLAGS:Q}
.endif
MAKE_FLAGS+=		LOCAL_LDFLAGS=${LDFLAGS:Q}

.if	${OPSYS} == "Linux"
SETUID_ROOT_PERMS?=	${REAL_ROOT_USER} shadow 2555
.elif ${OPSYS} == "OpenBSD"
SETUID_ROOT_PERMS?=	${REAL_ROOT_USER} _shadow 2555
.else
SETUID_ROOT_PERMS?=	${REAL_ROOT_USER} ${BINGRP} 4555
.endif
SPECIAL_PERMS+=		bin/xtrlock ${SETUID_ROOT_PERMS}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV}								\
	${MAKE_PROGRAM} ${MAKE_FLAGS} xtrlock

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtrlock								\
	${DESTDIR}${PREFIX}/bin/xtrlock

	${INSTALL_MAN} ${WRKSRC}/xtrlock.man								\
	${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/xtrlock.1

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
