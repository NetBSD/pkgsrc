# $NetBSD: Makefile,v 1.5 2011/10/08 14:11:22 wiz Exp $

DISTNAME=	gdata-2.0.14
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	www python
MASTER_SITES=	http://gdata-python-client.googlecode.com/files/

MAINTAINER=	mj@mjturner.net
HOMEPAGE=	http://code.google.com/p/gdata-python-client/
COMMENT=	Google Data API Python client library
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

PYDISTUTILSPKG=	yes
PY_PATCHPLIST=	yes

REPLACE_PYTHON+=	src/atom/__init__.py
REPLACE_PYTHON+=	src/atom/http.py
REPLACE_PYTHON+=	src/atom/http_interface.py
REPLACE_PYTHON+=	src/atom/mock_http.py
REPLACE_PYTHON+=	src/atom/mock_service.py
REPLACE_PYTHON+=	src/atom/service.py
REPLACE_PYTHON+=	src/atom/token_store.py
REPLACE_PYTHON+=	src/atom/url.py
REPLACE_PYTHON+=	src/gdata/Crypto/Util/RFC1751.py
REPLACE_PYTHON+=	src/gdata/__init__.py
REPLACE_PYTHON+=	src/gdata/alt/__init__.py
REPLACE_PYTHON+=	src/gdata/alt/appengine.py
REPLACE_PYTHON+=	src/gdata/apps/__init__.py
REPLACE_PYTHON+=	src/gdata/apps/emailsettings/__init__.py
REPLACE_PYTHON+=	src/gdata/apps/emailsettings/service.py
REPLACE_PYTHON+=	src/gdata/apps/migration/__init__.py
REPLACE_PYTHON+=	src/gdata/apps/migration/service.py
REPLACE_PYTHON+=	src/gdata/apps/service.py
REPLACE_PYTHON+=	src/gdata/auth.py
REPLACE_PYTHON+=	src/gdata/base/__init__.py
REPLACE_PYTHON+=	src/gdata/base/service.py
REPLACE_PYTHON+=	src/gdata/blogger/__init__.py
REPLACE_PYTHON+=	src/gdata/blogger/service.py
REPLACE_PYTHON+=	src/gdata/calendar/__init__.py
REPLACE_PYTHON+=	src/gdata/calendar/service.py
REPLACE_PYTHON+=	src/gdata/client.py
REPLACE_PYTHON+=	src/gdata/contacts/__init__.py
REPLACE_PYTHON+=	src/gdata/contacts/service.py
REPLACE_PYTHON+=	src/gdata/docs/__init__.py
REPLACE_PYTHON+=	src/gdata/docs/service.py
REPLACE_PYTHON+=	src/gdata/oauth/rsa.py
REPLACE_PYTHON+=	src/gdata/service.py
REPLACE_PYTHON+=	src/gdata/spreadsheet/__init__.py
REPLACE_PYTHON+=	src/gdata/spreadsheet/service.py
REPLACE_PYTHON+=	src/gdata/spreadsheet/text_db.py
REPLACE_PYTHON+=	src/gdata/test_data.py
REPLACE_PYTHON+=	src/gdata/urlfetch.py
REPLACE_PYTHON+=	src/gdata/webmastertools/__init__.py
REPLACE_PYTHON+=	src/gdata/webmastertools/service.py
REPLACE_PYTHON+=	src/gdata/youtube/__init__.py
REPLACE_PYTHON+=	src/gdata/youtube/service.py

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.if !empty(PYPKGPREFIX:Mpy24)
DEPENDS+=	${PYPKGPREFIX}-elementtree-[0-9]*:../../textproc/py-elementtree
.else
DEPENDS+=	${PYPKGPREFIX}-cElementTree-[0-9]*:../../textproc/py-cElementTree
.endif
.include "../../mk/bsd.pkg.mk"
