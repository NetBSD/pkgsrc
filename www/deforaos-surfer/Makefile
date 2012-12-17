# $NetBSD: Makefile,v 1.1 2012/12/17 01:36:28 khorben Exp $
#

DISTNAME=	Surfer-0.2.6
PKGNAME=	deforaos-surfer-0.2.6
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

.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
