# $NetBSD: Makefile,v 1.1.1.1 1999/09/29 15:32:49 tsarna Exp $

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "SunOS" && ${MACHINE_ARCH} == "sparc"
DISTUNAME=	solaris
WRKSRC=         ${WRKDIR}/Solaris
.elif (${MACHINE_ARCH} == "i386")
.if !exists(/emul/linux/lib/ld-linux.so.2)
IGNORE=	requires Linux glibc2 libraries - see compat_linux(8)
.endif
DISTUNAME=	linux
WRKSRC=         ${WRKDIR}/Linux
.endif

DISTVER=	4.0r12
DISTNAME=	flash_${DISTUNAME}
PKGNAME=	flashplayer-${DISTVER}
CATEGORIES=	www
MASTER_SITES=	http://download.macromedia.com/pub/shockwave/flash/english/${DISTUNAME}/${DISTVER}/

ONLY_FOR_PLATFORM= *-*-i386 # *-*-sparc

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.macromedia.com/software/flash/

NO_BUILD=	yes

NS_PLUGINS_DIR= ${PREFIX}/lib/netscape/plugins

do-install:
	${INSTALL_DATA_DIR} ${NS_PLUGINS_DIR}
	${INSTALL_DATA} ${WRKSRC}/* ${NS_PLUGINS_DIR}

.include "../../mk/bsd.pkg.mk"
