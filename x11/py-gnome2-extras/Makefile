# $NetBSD: Makefile,v 1.106 2022/08/11 05:09:32 gutteridge Exp $

DISTNAME=	gnome-python-extras-2.25.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/gnome-python/gnome2/}
PKGREVISION=	50
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-python-extras/2.25/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Python binding for GNOME2

# need xsltproc to build docs
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

PY_PATCHPLIST=			YES
PYTHON_VERSIONS_ACCEPTED=	27 # py-ORBit via py-gnome2
USE_LIBTOOL=			YES
PKGCONFIG_OVERRIDE+=		gnome-python-extras-2.0.pc.in
GNU_CONFIGURE=			YES
CONFIGURE_ENV+=			PYTHON=${PYTHONBIN:Q}
USE_TOOLS+=			pkg-config gmake
USE_LANGUAGES=			c c++
CONFIGURE_ARGS+=		--enable-docs

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
# newer gdl versions are incompatible
#.include "../../devel/gdl/buildlink3.mk"
# needs older version than is in pkgsrc
#.include "../../databases/libgda/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
# currently do not compile
#.include "../../wip/libgksu/buildlink3.mk"
#.include "../../wip/libgksuui/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
