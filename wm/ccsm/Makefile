# $NetBSD: Makefile,v 1.1.1.1 2008/05/12 12:08:13 jmcneill Exp $
#

DISTNAME=		ccsm-0.6.0
CATEGORIES=		wm gnome
MASTER_SITES=		http://releases.compiz-fusion.org/0.6.0/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.compiz-fusion.org/
COMMENT=		CompizConfig Settings Manager

USE_TOOLS+=		pkg-config gmake

PY_PATCHPLIST=		yes
PYDISTUTILSPKG=		yes
PYTHON_PATCH_SCRIPTS=	setup.py
PYTHON_PATCH_SCRIPTS+=	ccm/*.py

MAKE_ENV+=	PYTHONBIN=${PYTHONBIN:Q}

DEPENDS+=	compizconfig-backend-gconf>=0.6.0:../../devel/compizconfig-backend-gconf

.include "../../devel/py-compizconfig/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"

.include "../../mk/bsd.pkg.mk"
