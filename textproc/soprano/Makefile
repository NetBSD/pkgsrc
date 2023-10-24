# $NetBSD: Makefile,v 1.87 2023/10/24 22:11:20 wiz Exp $

DISTNAME=	soprano-2.9.4
PKGREVISION=	42
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=soprano/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://soprano.sourceforge.net/
COMMENT=	QT based RDF framework
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DSOPRANO_DISABLE_SESAME2_BACKEND:BOOL=ON

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

PKGCONFIG_OVERRIDE+=	soprano.pc.cmake

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../databases/iodbc/buildlink3.mk"
.include "../../textproc/libclucene/buildlink3.mk"
.include "../../textproc/redland/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
