# $NetBSD: Makefile,v 1.32 2010/03/24 04:55:20 obache Exp $
#

DISTNAME=	Trac-0.11.7.ja1
PKGNAME=	ja-${DISTNAME:tl:S/.ja/pl/}
CATEGORIES=	www devel
MASTER_SITES=	http://www.i-act.co.jp/project/products/downloads/
EXTRACT_SUFX=	.zip

MAINTAINER=	obache@NetBSD.org
HOMEPAGE=	http://www.i-act.co.jp/project/products/products.html
COMMENT=	Trac issue tracking system with Japanese localization
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	trac-[0-9]*

USE_LANGUAGES=	# none
USE_TOOLS+=	pax

DEPENDS+=	${PYPKGPREFIX}-genshi>=0.5:../../www/py-genshi

REPLACE_PYTHON= cgi-bin/trac.cgi cgi-bin/trac.fcgi
REPLACE_PYTHON+=contrib/*.py contrib/*-hook contrib/workflow/*.py
REPLACE_PYTHON+=trac/admin/templates/deploy_trac.* trac/tests/functional/*.py

.include "options.mk"

EGDIR=		share/examples/trac

INSTALLATION_DIRS+=	libexec/cgi-bin ${EGDIR}

post-install:
.for cgi in trac.cgi trac.fcgi
	${INSTALL_SCRIPT} ${WRKSRC}/cgi-bin/${cgi} ${DESTDIR}${PREFIX}/libexec/cgi-bin
.endfor
	cd ${WRKSRC}/contrib && \
		pax -rw -pp -pm . ${DESTDIR}${PREFIX}/${EGDIR}

MESSAGE_SUBST+=	PYPKGPREFIX=${PYPKGPREFIX}

# deploy template files
CHECK_INTERPRETER_SKIP+=	${PYSITELIB}/trac/admin/templates/deploy_*.*cgi

.include "../../lang/python/application.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
