# $NetBSD: Makefile,v 1.28 2018/11/14 22:22:39 kleink Exp $

DISTNAME=	Locker-0.4.0
PKGNAME=	deforaos-locker-0.4.0
PKGREVISION=	8
CATEGORIES=	x11
MASTER_SITES=	https://www.defora.org/os/download/download/4424/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop screensaver

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
AUTO_MKDIRS=	yes

LDFLAGS.SunOS+=	-lXext

.include "../../mk/bsd.prefs.mk"

.if ${PKGMANDIR} != "share/man"
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/locker.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/locker.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/lockerctl.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/lockerctl.1
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/locker.html ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/locker.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/lockerctl.html ${DESTDIR}${PREFIX}/share/doc/${PKGBASE}/lockerctl.html
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

.include "options.mk"

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
