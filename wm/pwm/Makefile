# $NetBSD: Makefile,v 1.5 2002/08/25 21:51:36 jlam Exp $
#

DISTNAME=	pwm-1.0
CATEGORIES=	wm x11
MASTER_SITES=	http://www.students.tut.fi/~tuomov/dl/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.students.tut.fi/~tuomov/pwm/
COMMENT=	Window manager that frames multiple client windows in a single frame

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_GMAKE=		YES
MAKE_ENV+=		SYSCONFDIR="${PKG_SYSCONFDIR}"

PKG_SYSCONFSUBDIR=	pwm
EGDIR=			${PREFIX}/share/examples/pwm
CONF_FILES=		${EGDIR}/pwm.conf ${PKG_SYSCONFDIR}/pwm.conf
SUPPS=			buttons-default.conf
SUPPS+=			keys-default.conf
SUPPS+=			menus-default.conf
SUPPS+=			look-beoslike.conf
SUPPS+=			look-brownsteel.conf
SUPPORT_FILES=		# empty
.for FILE in ${SUPPS}
SUPPORT_FILES+=		${EGDIR}/${FILE} ${PKG_SYSCONFDIR}/${FILE}
.endfor

post-install:
	${RM} -f ${EGDIR}/sample.conf

.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
