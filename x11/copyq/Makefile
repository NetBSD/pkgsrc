# $NetBSD: Makefile,v 1.2 2025/01/23 23:27:29 riastradh Exp $

DISTNAME=	copyq-9.1.0
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_GITHUB:=hluk/}
GH_PROJECT=	CopyQ
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	kikadf.01@gmail.com
COMMENT=	Qt5 based clipboard manager
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c c++
WRKSRC=		${WRKDIR}/${GH_PROJECT}-${PKGVERSION_NOREV}

.include "../../devel/cmake/build.mk"

BUILDLINK_API_DEPENDS.extra-cmake-modules+=	extra-cmake-modules>=5.19.0
.include "../../devel/extra-cmake-modules/buildlink3.mk"
.include "../../devel/knotifications/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/libXtst/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qtwayland/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
