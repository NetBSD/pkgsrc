# $NetBSD: Makefile,v 1.23 2008/06/20 01:09:39 joerg Exp $
#

DISTNAME=		glclock-6.0b6.0
PKGREVISION=		3
CATEGORIES=		x11 graphics time
MASTER_SITES=		http://www.daionet.gr.jp/~masa/archives/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.daionet.gr.jp/~masa/glclock/
COMMENT=		OpenGL-based pocket watch

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c++

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

.include "../../graphics/Mesa/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
