# $NetBSD: Makefile,v 1.18 2011/11/01 06:02:40 sbd Exp $

DISTNAME=		rsibreak-0.10
PKGREVISION=		7
CATEGORIES=		time kde
MASTER_SITES=		http://www.rsibreak.org/files/
EXTRACT_SUFX=           .tar.bz2

MAINTAINER=		markd@NetBSD.org
HOMEPAGE=		http://www.rsibreak.org/
COMMENT=		RSI management tool
LICENSE=		gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=		automoc4>=0.9.87:../../devel/automoc4

USE_TOOLS+=		msgfmt perl
USE_LANGUAGES=		c c++
USE_CMAKE=		yes

.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../x11/libXScrnSaver/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
