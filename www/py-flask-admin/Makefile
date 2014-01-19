# $NetBSD: Makefile,v 1.6 2014/01/19 17:38:12 wiz Exp $

DISTNAME=	Flask-Admin-1.0.7
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:tl}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://pypi.python.org/packages/source/F/Flask-Admin/

MAINTAINER=	kleink@NetBSD.org
HOMEPAGE=	https://github.com/mrjoes/flask-admin/
COMMENT=	Simple and extensible administrative interface framework for Flask
LICENSE=	modified-bsd

USE_LANGUAGES=	# empty

EGG_NAME=	${DISTNAME:S/-/_/}

DEPENDS+=	${PYPKGPREFIX}-flask>=0.7:../../www/py-flask
DEPENDS+=	${PYPKGPREFIX}-wtforms-[0-9]*:../../www/py-wtforms

# remove pre-compiled binaries
post-extract:
	${RM} ${WRKSRC}/flask_admin/tests/__pycache__/__init__.cpython-33.pyc
	${RM} ${WRKSRC}/flask_admin/tests/__pycache__/test_base.cpython-33.pyc
	${RM} ${WRKSRC}/flask_admin/tests/__pycache__/test_form_upload.cpython-33.pyc
	${RM} ${WRKSRC}/flask_admin/tests/__pycache__/test_model.cpython-33.pyc
	${RM} ${WRKSRC}/flask_admin/tests/fileadmin/__pycache__/__init__.cpython-33.pyc
	${RM} ${WRKSRC}/flask_admin/tests/fileadmin/__pycache__/test_fileadmin.cpython-33.pyc
	${RM} ${WRKSRC}/flask_admin/tests/mongoengine/__pycache__/__init__.cpython-33.pyc
	${RM} ${WRKSRC}/flask_admin/tests/mongoengine/__pycache__/test_basic.cpython-33.pyc
	${RM} ${WRKSRC}/flask_admin/tests/peeweemodel/__pycache__/__init__.cpython-33.pyc
	${RM} ${WRKSRC}/flask_admin/tests/peeweemodel/__pycache__/test_basic.cpython-33.pyc
	${RM} ${WRKSRC}/flask_admin/tests/pymongo/__pycache__/__init__.cpython-33.pyc
	${RM} ${WRKSRC}/flask_admin/tests/pymongo/__pycache__/test_basic.cpython-33.pyc
	${RM} ${WRKSRC}/flask_admin/tests/sqlamodel/__pycache__/__init__.cpython-33.pyc
	${RM} ${WRKSRC}/flask_admin/tests/sqlamodel/__pycache__/test_basic.cpython-33.pyc
	${RM} ${WRKSRC}/flask_admin/tests/sqlamodel/__pycache__/test_form_rules.cpython-33.pyc
	${RM} ${WRKSRC}/flask_admin/tests/sqlamodel/__pycache__/test_inlineform.cpython-33.pyc
	${RM} ${WRKSRC}/flask_admin/translations/__pycache__/__init__.cpython-33.pyc
	${RM} ${WRKSRC}/flask_admin/tests/__init__.pyc
	${RM} ${WRKSRC}/flask_admin/tests/fileadmin/__init__.pyc
	${RM} ${WRKSRC}/flask_admin/tests/fileadmin/test_fileadmin.pyc
	${RM} ${WRKSRC}/flask_admin/tests/mongoengine/__init__.pyc
	${RM} ${WRKSRC}/flask_admin/tests/mongoengine/test_basic.pyc
	${RM} ${WRKSRC}/flask_admin/tests/peeweemodel/__init__.pyc
	${RM} ${WRKSRC}/flask_admin/tests/peeweemodel/test_basic.pyc
	${RM} ${WRKSRC}/flask_admin/tests/pymongo/__init__.pyc
	${RM} ${WRKSRC}/flask_admin/tests/pymongo/test_basic.pyc
	${RM} ${WRKSRC}/flask_admin/tests/sqlamodel/__init__.pyc
	${RM} ${WRKSRC}/flask_admin/tests/sqlamodel/test_basic.pyc
	${RM} ${WRKSRC}/flask_admin/tests/sqlamodel/test_form_rules.pyc
	${RM} ${WRKSRC}/flask_admin/tests/sqlamodel/test_inlineform.pyc
	${RM} ${WRKSRC}/flask_admin/tests/test_base.pyc
	${RM} ${WRKSRC}/flask_admin/tests/test_form.pyc
	${RM} ${WRKSRC}/flask_admin/tests/test_form_upload.pyc
	${RM} ${WRKSRC}/flask_admin/tests/test_model.pyc
	${RM} ${WRKSRC}/flask_admin/translations/__init__.pyc

post-install:
.for i in LICENSE select2.min.js
	${CHMOD} -x \
	    ${DESTDIR}${PREFIX}/${PYSITELIB}/flask_admin/static/select2/${i}
.endfor

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
