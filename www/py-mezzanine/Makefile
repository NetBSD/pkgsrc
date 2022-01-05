# $NetBSD: Makefile,v 1.14 2022/01/05 15:41:30 wiz Exp $

DISTNAME=	Mezzanine-4.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=M/Mezzanine/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://mezzanine.jupo.org/
COMMENT=	Open source content management platform on Django
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-Pillow-[0-9]*:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-beautifulsoup4>=4.5.3:../../www/py-beautifulsoup4
DEPENDS+=	${PYPKGPREFIX}-bleach>=2.0:../../www/py-bleach
DEPENDS+=	${PYPKGPREFIX}-chardet-[0-9]*:../../converters/py-chardet
DEPENDS+=	${PYPKGPREFIX}-django>=1.8:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-contrib-comments-[0-9]*:../../www/py-django-contrib-comments
DEPENDS+=	${PYPKGPREFIX}-filebrowser_safe>=0.5.0:../../www/py-filebrowser_safe
DEPENDS+=	${PYPKGPREFIX}-future>=0.9.0:../../devel/py-future
DEPENDS+=	${PYPKGPREFIX}-grappelli_safe>=0.5.0:../../www/py-grappelli_safe
DEPENDS+=	${PYPKGPREFIX}-requests>=2.1.0:../../devel/py-requests
DEPENDS+=	${PYPKGPREFIX}-requests-oauthlib>=0.4.0:../../security/py-requests-oauthlib
DEPENDS+=	${PYPKGPREFIX}-tzlocal>=1.0:../../time/py-tzlocal
TEST_DEPENDS+=	${PYPKGPREFIX}-flakes>=0.6.1:../../devel/py-flakes
TEST_DEPENDS+=	${PYPKGPREFIX}-pep8>=1.4.1:../../devel/py-pep8

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-django-contrib-comments

USE_PKG_RESOURCES=	yes

REPLACE_PYTHON=	mezzanine/project_template/manage.py

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} mezzanine-project mezzanine-project-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
