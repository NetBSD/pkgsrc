# $NetBSD: Makefile,v 1.6 2001/10/24 22:11:08 jlam Exp $
#

DISTNAME=		glclock-6.0b6.0
CATEGORIES=		x11 graphics time
MASTER_SITES=		http://www.daionet.gr.jp/~masa/archives/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.daionet.gr.jp/~masa/glclock
COMMENT=		OpenGL-based pocket watch

MAKEFILE=		makefile
ALL_TARGET=		glclock
USE_BUILDLINK_ONLY=	yes

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

.include "../../graphics/Mesa/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
