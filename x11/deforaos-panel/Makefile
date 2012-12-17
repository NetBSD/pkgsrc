# $NetBSD: Makefile,v 1.1 2012/12/17 00:32:49 khorben Exp $
#

DISTNAME=	Panel-0.2.16
PKGNAME=	deforaos-panel-0.2.16
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/3948/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	http://www.defora.org/
COMMENT=	DeforaOS desktop panel

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
AUTO_MKDIRS=	yes

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/panel-embed.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/panel-embed.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/panel-message.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/panel-message.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/panel-notify.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/panel-notify.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/panel.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/panel.1
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/panelctl.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/panelctl.1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man/man1
	${RMDIR} ${DESTDIR}${PREFIX}/share/man

.include "options.mk"

.include "../../x11/deforaos-libdesktop/buildlink3.mk"
.include "../../sysutils/deforaos-browser/buildlink3.mk"
.include "../../x11/deforaos-keyboard/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
