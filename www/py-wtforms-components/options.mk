# $NetBSD: options.mk,v 1.1 2014/07/05 19:43:01 rodent Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-wtforms-components
PKG_SUPPORTED_OPTIONS=	arrow babel color ipaddress password phone tests
PKG_SUPPORTED_OPTIONS+=	timezone
PKG_SUGGESTED_OPTIONS+=	# blank

.include "../../mk/bsd.options.mk"

.include "../../lang/python/versioned_dependencies.mk"

.if !empty(PKG_OPTIONS:Marrow)
DEPENDS+=	${PYPKGPREFIX}-arrow>=0.3.4:../../time/py-arrow
.endif

.if !empty(PKG_OPTIONS:Mbabel)
DEPENDS+=	${PYPKGPREFIX}-babel>=1.3:../../devel/py-babel
.endif

.if !empty(PKG_OPTIONS:Mcolor)
DEPENDS+=	${PYPKGPREFIX}-colour>=0.0.4:../../textproc/py-colour
.endif

.if !empty(PKG_OPTIONS:Mipaddress)
DEPENDS+=	${PYPKGPREFIX}-ipaddr-[0-9]*:../../devel/py-ipaddr
.endif

.if !empty(PKG_OPTIONS:Mpassword)
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.6<2.0:../../security/py-passlib
.endif

.if !empty(PKG_OPTIONS:Mphone)
DEPENDS+=	${PYPKGPREFIX}-phonenumbers>=5.9.2:../../textproc/py-phonenumbers
.endif

.if !empty(PKG_OPTIONS:Mtests)
DEPENDS+=	${PYPKGPREFIX}-test>=2.2.3:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-pygments>=1.2:../../textproc/py-pygments
DEPENDS+=	${PYPKGPREFIX}-jinja2>=2.3:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-docutils>=0.10:../../textproc/py-docutils
DEPENDS+=	${PYPKGPREFIX}-flexmock>=0.9.7:../../devel/py-flexmock
DEPENDS+=	${PYPKGPREFIX}-psycopg2>=2.4.6:../../databases/py-psycopg2
DEPENDS+=	${PYPKGPREFIX}-pytz>=2014.2:../../time/py-pytz
DEPENDS+=	${PYPKGPREFIX}-pymysql-[0-9]*:../../databases/py-pymysql
DEPENDS+=	${PYPKGPREFIX}-arrow>=0.3.4:../../time/py-arrow
DEPENDS+=	${PYPKGPREFIX}-babel>=1.3:../../devel/py-babel
DEPENDS+=	${PYPKGPREFIX}-colour>=0.0.4:../../textproc/py-colour
DEPENDS+=       ${PYPKGPREFIX}-intervals>=0.2.4:../../math/py-intervals
DEPENDS+=	${PYPKGPREFIX}-ipaddr-[0-9]*:../../devel/py-ipaddr
DEPENDS+=	${PYPKGPREFIX}-passlib>=1.6<2.0:../../security/py-passlib
DEPENDS+=	${PYPKGPREFIX}-phonenumbers>=5.9.2:../../textproc/py-phonenumbers
DEPENDS+=	${PYPKGPREFIX}-wtforms-test>=0.1.1:../../www/py-wtforms-test
PYTHON_VERSIONED_DEPENDENCIES+=	dateutil
.endif

.if !empty(PKG_OPTIONS:Mtimezone)
PYTHON_VERSIONED_DEPENDENCIES+=	dateutil
.endif
