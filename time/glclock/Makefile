# $NetBSD: Makefile,v 1.12 2004/10/03 00:18:22 tv Exp $
#

DISTNAME=		glclock-6.0b6.0
PKGREVISION=		2
CATEGORIES=		x11 graphics time
MASTER_SITES=		http://www.daionet.gr.jp/~masa/archives/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.daionet.gr.jp/~masa/glclock
COMMENT=		OpenGL-based pocket watch

MAKEFILE=		makefile
ALL_TARGET=		glclock

USE_BUILDLINK3=		yes
USE_X11=		# defined

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

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
