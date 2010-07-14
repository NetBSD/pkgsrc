# $NetBSD: Makefile,v 1.6 2010/07/14 11:11:30 sbd Exp $
#

DISTNAME=	konq-plugins-4.4.0
PKGREVISION=	2
CATEGORIES=	www kde
MASTER_SITES=	${MASTER_SITE_KDE:=4.4.0/src/extragear/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://extragear.kde.org/
COMMENT=	Konqueror plugins (KDE4)
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	automoc4>=0.9.83:../../devel/automoc4

PKG_DESTDIR_SUPPORT=	user-destdir
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

USE_CMAKE=	yes
USE_TOOLS+=	msgfmt pkg-config

.include "../../www/tidy/buildlink3.mk"
.include "../../x11/kdebase4/buildlink3.mk"
.include "../../x11/kdelibs4/buildlink3.mk"
.include "../../meta-pkgs/kde4/kde4.mk"
.include "../../mk/bsd.pkg.mk"
