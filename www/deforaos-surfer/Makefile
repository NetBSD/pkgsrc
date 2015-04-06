# $NetBSD: Makefile,v 1.21 2015/04/06 08:17:39 adam Exp $

DISTNAME=	Surfer-0.2.7
PKGNAME=	deforaos-surfer-0.2.7
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://www.defora.org/os/download/download/4345/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop web browser
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
AUTO_MKDIRS=	yes

OPSYSVARS+=		MAKE_ENV
MAKE_ENV.SunOS+=	LDFLAGSF="-lnsl -lresolv"

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/download.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/download.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/helper.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/helper.html
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/surfer.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/surfer.html
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/download.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/download.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/helper.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/helper.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/surfer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/surfer.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../www/webkit1-gtk/buildlink3.mk"
.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
