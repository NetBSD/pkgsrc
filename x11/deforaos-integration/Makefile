# $NetBSD: Makefile,v 1.25 2020/06/02 08:24:59 adam Exp $

DISTNAME=	Integration-0.1.0
PKGNAME=	deforaos-integration-0.1.0
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	https://ftp.defora.org/pub/DeforaOS/Apps/Desktop/src/Integration/

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://www.defora.org/
COMMENT=	DeforaOS desktop integration

LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config
USE_TOOLS+=	xgettext

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

DEPENDS+=	deforaos-icon-theme>=0.1.1:../../graphics/deforaos-icon-theme

MAKE_FLAGS+=	DESTDIR=${DESTDIR}
MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	CFLAGS=${CFLAGS:Q}
AUTO_MKDIRS=	yes

.include "../../mk/bsd.prefs.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../devel/sofia-sip/buildlink3.mk"
.include "../../comms/deforaos-phone/buildlink3.mk"
.include "../../multimedia/deforaos-player/buildlink3.mk"
.include "../../x11/deforaos-keyboard/buildlink3.mk"
.include "../../x11/deforaos-locker/buildlink3.mk"
.include "../../x11/deforaos-panel/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
