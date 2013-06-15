# $NetBSD: Makefile,v 1.6 2013/06/15 12:47:46 khorben Exp $
#

DISTNAME=	Panel-0.2.18
PKGNAME=	deforaos-panel-0.2.18
CATEGORIES=	x11
MASTER_SITES=	http://www.defora.org/os/download/download/4295/

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
.include "../../multimedia/deforaos-player/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
