# $NetBSD: Makefile,v 1.15 2014/05/05 00:48:26 ryoon Exp $
#

DISTNAME=	Surfer-0.2.6
PKGNAME=	deforaos-surfer-0.2.6
PKGREVISION=	14
CATEGORIES=	www
MASTER_SITES=	http://www.defora.org/os/download/download/3709/

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

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/download.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/download.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/helper.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/helper.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/surfer.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/surfer.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
