# $NetBSD: Makefile,v 1.39 2019/11/26 13:34:05 wiz Exp $

DISTNAME=	pwm-20070720
CATEGORIES=	wm x11
MASTER_SITES=	https://tuomov.iki.fi/software/dl/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	https://tuomov.iki.fi/software/
COMMENT=	Window manager that frames multiple client windows in a single frame

# pwm is linked against libtu.a before it is build.
MAKE_JOBS_SAFE=	no

CONFLICTS+=	ion<=20040729nb2

USE_TOOLS+=	gmake

CFLAGS+=	-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""
MAKE_FLAGS+=	MANDIR=${PREFIX}/${PKGMANDIR}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
MAKE_FLAGS+=	HAS_SYSTEM_ASPRINTF=1
.endif

PKG_SYSCONFSUBDIR=	pwm

EGDIR=		${PREFIX}/share/examples/pwm
CONF_FILES=	${EGDIR}/pwm.conf.default ${PKG_SYSCONFDIR}/pwm.conf

CONFS=		buttons-default.conf
CONFS+=		keys-default.conf
CONFS+=		menus-default.conf
CONFS+=		look-beoslike.conf
CONFS+=		look-brownsteel.conf
CONFS+=		look-cdelike.conf
.for f in ${CONFS}
CONF_FILES+=	${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

post-install:
	${INSTALL_DATA} ${FILESDIR}/look-cdelike.conf ${DESTDIR}${EGDIR}

.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
