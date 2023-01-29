# $NetBSD: Makefile,v 1.47 2023/01/29 21:17:57 ryoon Exp $

DISTNAME=	bmpanel2-2.1pre1
PKGREVISION=	33
CATEGORIES=	wm sysutils
MASTER_SITES=	http://bmpanel2.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nsf/bmpanel2
COMMENT=	NETWM-compatible panel for X11
LICENSE=	mit

TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

REPLACE_PYTHON=			extra/py/bmpanel2.py
PYDISTUTILSPKG=			no

EGG_NAME=	bmpanel2cfg-1.0

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

SUBST_CLASSES+=		prefix
SUBST_SED.prefix=	-e "s,/usr/local,${PREFIX},g"
SUBST_FILES.prefix=	xdg.c
SUBST_STAGE.prefix=	post-extract
SUBST_MESSAGE.prefix=	Fixing path to themes.

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
