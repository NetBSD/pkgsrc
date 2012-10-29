# $NetBSD: Makefile,v 1.10 2012/10/29 05:06:10 asau Exp $

DISTNAME=	dtxsession-1.0
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sun.com/software/solaris/cde/
COMMENT=	Launch a X11 session from CDE login service

ONLY_FOR_PLATFORM=	SunOS-*-*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
LOCALBASE=	/usr/dt
.endif
NO_BUILD=	YES

CONFIG_DIR=	${PREFIX}/config

INSTALLATION_DIRS=	${CONFIG_DIR}/C/Xresources.d appconfig/icons/C

do-install:
	${INSTALL_DATA} ${FILESDIR}/Xresources.X11 ${DESTDIR}${CONFIG_DIR}/C/Xresources.d
	${INSTALL_SCRIPT} ${FILESDIR}/Xsession.X11 ${DESTDIR}${CONFIG_DIR}
	${INSTALL_DATA} ${FILESDIR}/X11.?m ${DESTDIR}${PREFIX}/appconfig/icons/C

.include "../../mk/bsd.pkg.mk"
