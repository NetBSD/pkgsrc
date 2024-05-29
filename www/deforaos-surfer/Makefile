# $NetBSD: Makefile,v 1.78 2024/05/29 16:34:48 adam Exp $

DISTNAME=	Surfer-0.3.1
PKGNAME=	deforaos-surfer-0.3.1
PKGREVISION=	12
CATEGORIES=	www
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Surfer/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop web browser
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

LDFLAGS.SunOS+=	-lsocket -lnsl

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=	LDFLAGS=${LDFLAGS:Q}
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

.if ${PKGMANDIR} != "share/man"
post-install:
. for page in download helper htmlapp surfer
	${MV} ${DESTDIR}${PREFIX}/share/man/html1/${page}.html ${DESTDIR}${PREFIX}/${PKGMANDIR}/html1/${page}.html
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/${page}.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/${page}.1
. endfor
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/html1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man
.endif

.include "options.mk"

.include "../../devel/deforaos-configure/deforaos-configure.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
