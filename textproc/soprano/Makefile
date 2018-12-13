# $NetBSD: Makefile,v 1.58 2018/12/13 19:51:38 adam Exp $

DISTNAME=	soprano-2.9.4
PKGREVISION=	16
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=soprano/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	markd@NetBSD.org
HOMEPAGE=	http://soprano.sourceforge.net/
COMMENT=	QT based RDF framework
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c c++03
USE_CMAKE=	yes
USE_TOOLS+=	pkg-config

CMAKE_ARGS+=	-DSOPRANO_DISABLE_SESAME2_BACKEND:BOOL=ON

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
