# $NetBSD: Makefile,v 1.56 2020/04/12 08:29:16 adam Exp $

DISTNAME=	Surfer-0.3.0
PKGNAME=	deforaos-surfer-0.3.0
PKGREVISION=	3
CATEGORIES=	www
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Surfer/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop web browser
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

LDFLAGS.SunOS+=	-lsocket -lnsl

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

.if ${PKGMANDIR} != "share/man"
post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/download.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/download.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/htmlapp.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/htmlapp.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/helper.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/helper.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/surfer.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/surfer.html
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/download.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/download.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/helper.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/helper.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/htmlapp.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/htmlapp.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/surfer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/surfer.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../www/webkit24-gtk3/buildlink3.mk"
.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
