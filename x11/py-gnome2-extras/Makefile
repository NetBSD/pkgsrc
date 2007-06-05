# $NetBSD: Makefile,v 1.20 2007/06/05 05:37:40 wiz Exp $
#

DISTNAME=	gnome-python-extras-2.14.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/gnome-python/gnome2/}
PKGREVISION=	2
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-python-extras/2.14/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python binding for GNOME2

PY_PATCHPLIST=	YES
USE_LIBTOOL=	YES
PKGCONFIG_OVERRIDE+=	gnome-python-extras-2.0.pc.in
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}
USE_TOOLS+=		pkg-config

PYTHON_VERSIONS_ACCEPTED=	24

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
# XXX optional? or firefox?
# seamonkey untested.
#.include "../../www/seamonkey/buildlink3.mk"
.include "../../textproc/gtkspell/buildlink3.mk"
.include "../../devel/gdl/buildlink3.mk"
# needs older version than is in pkgsrc
#.include "../../databases/libgda/buildlink3.mk"
.include "../../x11/py-gnome2/buildlink3.mk"
# currently do not compile
#.include "../../wip/libgksu/buildlink3.mk"
#.include "../../wip/libgksuui/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
