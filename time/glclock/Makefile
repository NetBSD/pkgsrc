# $NetBSD: Makefile,v 1.3 2001/02/17 17:32:03 wiz Exp $
#

DISTNAME=		glclock-6.0b6.0
CATEGORIES=		x11 graphics time
MASTER_SITES=		http://www.daionet.gr.jp/~masa/archives/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.daionet.gr.jp/~masa/glclock
COMMENT=		OpenGL-based pocket watch

USE_X11BASE=		yes
USE_MESA=		yes
MAKEFILE=		makefile
ALL_TARGET=		glclock

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == NetBSD && ${MACHINE_ARCH} == sparc
CFLAGS=
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glclock ${PREFIX}/bin
#notyet: lookup of .ppm files
#	for i in benchclock crystalclock marbleclock metalclock \
#			mwclock woodclock;do \
#	${INSTALL_SCRIPT} ${WRKSRC}/$$i ${PREFIX}/bin; done

.include "../../mk/bsd.pkg.mk"
