# $NetBSD: Makefile,v 1.2 2003/07/17 22:56:22 grant Exp $

DISTNAME=	dtxsession-1.0
CATEGORIES=	x11
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	tron@NetBSD.org
HOMEPAGE=	http://www.sun.com/solaris/cde/
COMMENT=	Launch a X11 session from CDE login service

ONLY_FOR_PLATFORM=	SunOS-*-*

.include "../../mk/bsd.prefs.mk"

LOCALBASE=	/usr/dt
NO_BUILD=	YES
NO_CHECKSUM=	YES
NO_MTREE=	YES

CONFIG_DIR=	${PREFIX}/config

do-install:
	${INSTALL_DATA} ${FILESDIR}/Xresources.X11 ${CONFIG_DIR}/C/Xresources.d
	${INSTALL_SCRIPT} ${FILESDIR}/Xsession.X11 ${CONFIG_DIR}
	${INSTALL_DATA} ${FILESDIR}/X11.?m ${PREFIX}/appconfig/icons/C

.include "../../mk/bsd.pkg.mk"
