# $NetBSD: Makefile,v 1.35 2022/07/11 01:36:50 khorben Exp $

DISTNAME=	Locker-0.4.2
PKGNAME=	deforaos-locker-0.4.2
CATEGORIES=	x11
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Locker/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop screensaver
LICENSE=	2-clause-bsd

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

.include "../../devel/deforaos-configure/deforaos-configure.mk"
.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
BUILDLINK_API_DEPENDS.gtk-doc+=	gtk-doc>=1.32nb9
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
