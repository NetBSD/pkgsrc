# $NetBSD: Makefile,v 1.47 2011/11/01 06:03:05 sbd Exp $
#

DISTNAME=	gnome-python-extras-2.25.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/gnome-python/gnome2/}
PKGREVISION=	4
CATEGORIES=	x11 python
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-python-extras/2.25/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python binding for GNOME2

# need xsltproc to build docs
BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl

PKG_DESTDIR_SUPPORT=	user-destdir

PY_PATCHPLIST=	YES
USE_LIBTOOL=	YES
PKGCONFIG_OVERRIDE+=	gnome-python-extras-2.0.pc.in
GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN:Q}
USE_TOOLS+=		pkg-config gmake autoconf automake
USE_LANGUAGES=	c c++
CONFIGURE_ARGS+=	--with-gtkmozembed=xulrunner-1.9
CONFIGURE_ARGS+=	--enable-docs

PYTHON_VERSIONS_ACCEPTED=	27 26 25

pre-configure:
	${RM} -f ${WRKSRC}/gtkmozembed/gtkmozembedmodule.c
	${RUN}cd ${WRKSRC};aclocal;autoheader;automake;autoconf

# for libtool happy
BUILDLINK_FNAME_TRANSFORM.xulrunner+=	-e 's|/libxpcomglue.a|/libxpcomglue_pic.a|g'	
BUILDLINK_TRANSFORM+=	l:xpcomglue:xpcomglue_pic

.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"

.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/xulrunner192/buildlink3.mk"
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
