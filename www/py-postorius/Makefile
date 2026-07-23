# $NetBSD: Makefile,v 1.7 2026/07/23 20:39:30 markd Exp $

DISTNAME=	postorius-1.3.13
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/postorius/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.com/mailman/postorius
COMMENT=	The New Mailman Web UI
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-pdm_backend-[0-9]*:../../devel/py-pdm_backend
DEPENDS+=	${PYPKGPREFIX}-comrak-[0-9]*:../../textproc/py-comrak
DEPENDS+=	${PYPKGPREFIX}-django>=4.2:../../www/py-django
DEPENDS+=	${PYPKGPREFIX}-django-mailman3>=1.3.13:../../www/py-django-mailman3
DEPENDS+=	${PYPKGPREFIX}-mailmanclient>=3.3.3:../../mail/py-mailmanclient
DEPENDS+=	${PYPKGPREFIX}-readme_renderer-[0-9]*:../../textproc/py-readme_renderer
# readme_renderer[md]
DEPENDS+=	${PYPKGPREFIX}-cmarkgfm>=0.8.0:../../textproc/py-cmarkgfm

USE_LANGUAGES=	# none

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PYSITELIB}/postorius/static/postorius/js/held_messages.js.orig

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
