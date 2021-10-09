# $NetBSD: Makefile,v 1.19 2021/10/09 10:54:06 nia Exp $

PKGNAME=	${PYPKGPREFIX}-cElementTree-${PY_DISTVERSION}
CATEGORIES=	textproc python

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.effbot.org/zone/celementtree.htm
COMMENT=	C implementation of Python ElementTree API

# "error: 'for' loop initial declarations are only allowed in C99 mode"
USE_LANGUAGES=	c99

USE_GCC_RUNTIME=	yes

PYDISTUTILSPKG=		yes
PY_SETUP_SUBST+=	EXPATPREFIX=${BUILDLINK_DIR}
PY_SETUP_SUBST+=	EXPATRTPREFIX=${BUILDLINK_PREFIX.expat}

PYSETUPINSTALLARGS+=	--install-lib ${PREFIX}/${PYLIB}/lib-dynload

.include "../../textproc/expat/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/srcdist.mk"
.include "../../mk/bsd.pkg.mk"
