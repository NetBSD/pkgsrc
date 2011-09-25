# $NetBSD: Makefile,v 1.10 2011/09/25 20:09:00 joerg Exp $

DISTNAME=	uwsgi-0.9.8.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://projects.unbit.it/downloads/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://projects.unbit.it/uwsgi
COMMENT=	Feature-rich WSGI server
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-setuptools>=0.6c9:../../devel/py-setuptools

PYTHON_VERSIONS_ACCEPTED=	27 26 25

USE_LANGUAGES=		c
PYDISTUTILSPKG=		yes

PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	mv ${DESTDIR}${PREFIX}/bin/uwsgi ${DESTDIR}${PREFIX}/bin/uwsgi-${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
