# $NetBSD: Makefile,v 1.7 2003/06/01 16:16:59 salo Exp $
#

DISTNAME=	pwm-20030528
PKGNAME=	${DISTNAME:S/-/-1.0./}
CATEGORIES=	wm x11
MASTER_SITES=	http://modeemi.cs.tut.fi/~tuomov/dl/

MAINTAINER=	salo@netbsd.org
HOMEPAGE=	http://www.students.tut.fi/~tuomov/pwm/
COMMENT=	Window manager that frames multiple client windows in a single frame

USE_BUILDLINK2=		YES
USE_PKGINSTALL=		YES
USE_X11=		YES
USE_GMAKE=		YES

CFLAGS+=		-DPKG_SYSCONFDIR=\"\\\"${PKG_SYSCONFDIR}\\\"\"

PKG_SYSCONFSUBDIR=	pwm

EGDIR=			${PREFIX}/share/examples/pwm
CONF_FILES=		${EGDIR}/pwm.conf.default ${PKG_SYSCONFDIR}/pwm.conf

SUPPS=			buttons-default.conf
SUPPS+=			keys-default.conf
SUPPS+=			menus-default.conf
SUPPS+=			look-beoslike.conf
SUPPS+=			look-brownsteel.conf
SUPPORT_FILES=		# empty
.for FILE in ${SUPPS}
SUPPORT_FILES+=		${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor

.include "../../mk/bsd.pkg.mk"
