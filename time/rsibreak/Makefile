# $NetBSD: Makefile,v 1.60 2018/08/16 18:55:13 adam Exp $

DISTNAME=		rsibreak-0.11
PKGREVISION=		36
CATEGORIES=		time kde
MASTER_SITES=		http://www.rsibreak.org/files/
EXTRACT_SUFX=           .tar.bz2

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://www.rsibreak.org/
COMMENT=		RSI management tool
LICENSE=		gnu-gpl-v2

BUILD_DEPENDS+=		automoc4>=0.9.87:../../devel/automoc4

USE_TOOLS+=		msgfmt perl
USE_LANGUAGES=		c c++

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"

.include "../../mk/bsd.pkg.mk"
