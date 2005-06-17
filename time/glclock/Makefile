# $NetBSD: Makefile,v 1.16 2005/06/17 03:50:38 jlam Exp $
#

DISTNAME=		glclock-6.0b6.0
PKGREVISION=		2
CATEGORIES=		x11 graphics time
MASTER_SITES=		http://www.daionet.gr.jp/~masa/archives/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.daionet.gr.jp/~masa/glclock
COMMENT=		OpenGL-based pocket watch

MAKEFILE=		makefile
BUILD_TARGET=		glclock


.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == NetBSD && ${MACHINE_ARCH} == sparc
CFLAGS=
.endif

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glclock ${PREFIX}/bin
#notyet: lookup of .ppm files
#	for i in benchclock crystalclock marbleclock metalclock \
#			mwclock woodclock;do \
#	${INSTALL_SCRIPT} ${WRKSRC}/$$i ${PREFIX}/bin; done

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
