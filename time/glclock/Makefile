# $NetBSD: Makefile,v 1.31 2022/08/11 05:09:20 gutteridge Exp $
#

DISTNAME=		glclock-6.0b6.0
PKGREVISION=		7
CATEGORIES=		x11 graphics time
MASTER_SITES=		http://www.daionet.gr.jp/~masa/archives/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.daionet.gr.jp/~masa/glclock/
COMMENT=		OpenGL-based pocket watch

USE_LANGUAGES=		c++03

MAKE_FILE=		makefile
BUILD_TARGET=		glclock


.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == NetBSD && ${MACHINE_ARCH} == sparc
CFLAGS=
.endif

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/glclock ${DESTDIR}${PREFIX}/bin
#notyet: lookup of .ppm files
#	for i in benchclock crystalclock marbleclock metalclock \
#			mwclock woodclock;do \
#	${INSTALL_SCRIPT} ${WRKSRC}/$$i ${PREFIX}/bin; done

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freeglut/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
