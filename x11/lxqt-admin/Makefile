# $NetBSD: Makefile,v 1.45 2026/04/28 08:16:11 pin Exp $

.include "../../meta-pkgs/lxqt/Makefile.common"

DISTNAME=	lxqt-admin-2.4.0
CATEGORIES=	x11

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/lxqt/lxqt-admin/
COMMENT=	LXQt admin panel
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config perl

TOOL_DEPENDS+=	lxqt-build-tools>=2.4.0:../../devel/lxqt-build-tools
TOOL_DEPENDS+=	qt6-qttools-[0-9]*:../../devel/qt6-qttools
DEPENDS+=	lxqt-policykit-[0-9]*:../../security/lxqt-policykit

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../security/polkit-qt6/buildlink3.mk"
.include "../../x11/liblxqt/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
