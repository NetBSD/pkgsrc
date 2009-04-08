# $NetBSD: Makefile,v 1.7 2009/04/08 22:43:26 joerg Exp $

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
NO_CHECKSUM=	YES

CONFIG_DIR=	${PREFIX}/config

do-install:
	${INSTALL_DATA_DIR} ${CONFIG_DIR}/C/Xresources.d
	${INSTALL_DATA} ${FILESDIR}/Xresources.X11 ${CONFIG_DIR}/C/Xresources.d
	${INSTALL_SCRIPT} ${FILESDIR}/Xsession.X11 ${CONFIG_DIR}
	${INSTALL_DATA_DIR} ${PREFIX}/appconfig/icons/C
	${INSTALL_DATA} ${FILESDIR}/X11.?m ${PREFIX}/appconfig/icons/C

.include "../../mk/bsd.pkg.mk"
