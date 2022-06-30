# $NetBSD: Makefile,v 1.45 2022/06/30 11:18:56 nia Exp $

DISTNAME=	bmpanel2-2.1pre1
PKGREVISION=	31
CATEGORIES=	wm sysutils
MASTER_SITES=	http://bmpanel2.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/nsf/bmpanel2
COMMENT=	NETWM-compatible panel for X11
LICENSE=	mit

BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config gzip

REPLACE_PYTHON=			extra/py/bmpanel2.py
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 2.1pre1
PY_PATCHPLIST=			yes

INSTALLATION_DIRS+=	${PKGMANDIR}/man1

SUBST_CLASSES+=		prefix
SUBST_SED.prefix=	-e "s,/usr/local,${PREFIX},g"
SUBST_FILES.prefix=	xdg.c
SUBST_STAGE.prefix=	post-extract
SUBST_MESSAGE.prefix=	Fixing path to themes.

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/* ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
