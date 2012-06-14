# $NetBSD: Makefile,v 1.15 2012/06/14 07:45:19 sbd Exp $

DISTNAME=	uwsgi-0.9.8.6
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	www python
MASTER_SITES=	http://projects.unbit.it/downloads/

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	http://projects.unbit.it/uwsgi
COMMENT=	Feature-rich WSGI server
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${PYPKGPREFIX}-setuptools>=0.6c9:../../devel/py-setuptools

USE_LANGUAGES=		c
PYDISTUTILSPKG=		yes

PLIST_SUBST+=		PYVERSSUFFIX=${PYVERSSUFFIX}

post-install:
	mv ${DESTDIR}${PREFIX}/bin/uwsgi ${DESTDIR}${PREFIX}/bin/uwsgi-${PYVERSSUFFIX}

.include "../../lang/python/extension.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
