# $NetBSD: Makefile,v 1.14 2005/02/04 13:58:32 wiz Exp $
#

DISTNAME=	pwm-20030617
PKGNAME=	${DISTNAME:S/-/-1.0./}
CATEGORIES=	wm x11
MASTER_SITES=	http://modeemi.fi/~tuomov/dl/

MAINTAINER=	salo@NetBSD.org
HOMEPAGE=	http://modeemi.fi/~tuomov/pwm/
COMMENT=	Window manager that frames multiple client windows in a single frame

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS+=	ion-[0-9]*

USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
USE_X11=	YES
USE_GNU_TOOLS+=	make

CFLAGS+=	-DPKG_SYSCONFDIR=\"\\\"${PKG_SYSCONFDIR}\\\"\"

PKG_SYSCONFSUBDIR=	pwm

EGDIR=		${PREFIX}/share/examples/pwm
CONF_FILES=	${EGDIR}/pwm.conf.default ${PKG_SYSCONFDIR}/pwm.conf

SUPPS=		buttons-default.conf
SUPPS+=		keys-default.conf
SUPPS+=		menus-default.conf
SUPPS+=		look-beoslike.conf
SUPPS+=		look-brownsteel.conf
SUPPORT_FILES=	# empty
.for FILE in ${SUPPS}
SUPPORT_FILES+=	${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor

.include "../../mk/bsd.pkg.mk"
