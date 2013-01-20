# $NetBSD: Makefile,v 1.41 2013/01/20 08:56:48 obache Exp $
#

DISTNAME=	Trac-1.0.ja1
PKGNAME=	ja-${DISTNAME:tl:S/.ja/pl/}
CATEGORIES=	www devel
MASTER_SITES=	http://www.i-act.co.jp/project/products/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.i-act.co.jp/project/products/products.html
COMMENT=	Trac issue tracking system with Japanese localization
LICENSE=	modified-bsd

CONFLICTS+=	trac-[0-9]*

USE_LANGUAGES=	# none
USE_TOOLS+=	pax

DEPENDS+=	${PYPKGPREFIX}-genshi>=0.6:../../www/py-genshi
DEPENDS+=	${PYPKGPREFIX}-babel>=0.9.5:../../devel/py-babel

REPLACE_PYTHON= contrib/cgi-bin/trac.cgi contrib/cgi-bin/trac.fcgi
REPLACE_PYTHON+=contrib/*.py contrib/*-hook contrib/workflow/*.py
REPLACE_PYTHON+=trac/admin/templates/deploy_trac.* trac/tests/functional/*.py

.include "options.mk"

EGDIR=		share/examples/trac

INSTALLATION_DIRS+=	libexec/cgi-bin ${EGDIR}

post-install:
.for cgi in trac.cgi trac.fcgi
	${INSTALL_SCRIPT} ${WRKSRC}/contrib/cgi-bin/${cgi} ${DESTDIR}${PREFIX}/libexec/cgi-bin
.endfor
	cd ${WRKSRC}/contrib && \
		pax -rw -pp -pm . ${DESTDIR}${PREFIX}/${EGDIR}

MESSAGE_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

# deploy template files
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/trac/admin/templates/deploy_*.*gi

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
