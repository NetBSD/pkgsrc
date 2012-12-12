# $NetBSD: Makefile,v 1.1 2012/12/12 15:18:45 wiz Exp $
#

DISTNAME=	razorqt-0.5.1
CATEGORIES=	x11
MASTER_SITES=	https://github.com/downloads/Razor-qt/razor-qt/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.razor-qt.org/
COMMENT=	Advanced, fast Qt environment without window manager
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	doxygen-[0-9]*:../../devel/doxygen

FETCH_USING=	curl
USE_LANGUAGES=	c c++
USE_TOOLS+=	bash pkg-config
USE_CMAKE=	yes

REPLACE_BASH+=	razorqt-session/razor-session/resources/xdg-mime
REPLACE_BASH+=	razorqt-session/razor-session/resources/xdg-open
REPLACE_SH+=	razorqt-session/razor-session/resources/xdg-screensaver
REPLACE_PYTHON+=	razorqt-confupdate/updates/razor-0.5/desktop-041-050.py
CHECK_PORTABILITY_SKIP=	razorqt-session/razor-session/resources/xdg-screensaver

.include "../../lang/python/application.mk"
.include "../../audio/pulseaudio/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/xscreensaver/buildlink3.mk"
.include "../../x11/libXcomposite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
