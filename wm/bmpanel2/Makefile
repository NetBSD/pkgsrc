# $NetBSD: Makefile,v 1.3 2011/12/09 00:15:36 dholland Exp $
#

DISTNAME=	bmpanel2-2.1pre1
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://bmpanel2.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/bmpanel2/
COMMENT=	NETWM-compatible panel for X11
LICENSE=	mit

PKG_DESTDIR_SUPPORT=	user-destdir
USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

PY_PATCHPLIST=	yes
REPLACE_PYTHON=	extra/py/bmpanel2.py

SUBST_CLASSES+=		prefix
SUBST_SED.prefix=	-e "s,/usr/local,${PREFIX},g"
SUBST_FILES.prefix=	xdg.c
SUBST_STAGE.prefix=	post-extract
SUBST_MESSAGE.prefix=	Fixing path to themes.

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
