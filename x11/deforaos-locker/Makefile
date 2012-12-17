# $NetBSD: Makefile,v 1.1 2012/12/17 00:47:37 khorben Exp $
#

DISTNAME=	Locker-0.2.1
PKGNAME=	deforaos-locker-0.2.1
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3703/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop screensaver

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
AUTO_MKDIRS=	yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/locker.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/locker.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/lockerctl.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/lockerctl.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man

.include "options.mk"

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../x11/deforaos-panel/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
