# $NetBSD: Makefile,v 1.24 2006/02/05 23:11:14 joerg Exp $
#

DISTNAME=	pwm-20030617
PKGNAME=	${DISTNAME:S/-/-1.0./}
PKGREVISION=	2
CATEGORIES=	wm x11
MASTER_SITES=	http://modeemi.fi/~tuomov/dl/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://modeemi.fi/~tuomov/pwm/
COMMENT=	Window manager that frames multiple client windows in a single frame

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	ion<=20040729nb2

USE_TOOLS+=	gmake

CFLAGS+=	-DPKG_SYSCONFDIR="\"${PKG_SYSCONFDIR}\""

PKG_SYSCONFSUBDIR=	pwm

EGDIR=		${PREFIX}/share/examples/pwm
CONF_FILES=	${EGDIR}/pwm.conf.default ${PKG_SYSCONFDIR}/pwm.conf

CONFS=		buttons-default.conf
CONFS+=		keys-default.conf
CONFS+=		menus-default.conf
CONFS+=		look-beoslike.conf
CONFS+=		look-brownsteel.conf
.for FILE in ${CONFS}
CONF_FILES+=	${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
