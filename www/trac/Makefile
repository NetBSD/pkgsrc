# $NetBSD: Makefile,v 1.86 2019/06/11 05:30:23 maya Exp $

DISTNAME=	Trac-1.2.3
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	devel www
MASTER_SITES=	http://ftp.edgewall.org/pub/trac/

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://trac.edgewall.org/
COMMENT=	Repository browser, wiki, and issue tracking system
LICENSE=	modified-bsd

# Updates to micro-releases along stable branches are commited without
# testing.
#
# Trac supports svn and git in the base, plus others via plugins,
# using them at runtime if configured.  Therefore this package does
# not depend on svn or git to avoid installing them for trac installs
# that use the other.

DEPENDS+=	${PYPKGPREFIX}-genshi>=0.6:../../www/py-genshi

USE_TOOLS+=	pax

# The Trac 1.2 series does not support python 3.
PYTHON_VERSIONS_INCOMPATIBLE=	36 37

REPLACE_PYTHON=	contrib/cgi-bin/trac.* contrib/*.py contrib/*-hook
REPLACE_PYTHON+=	trac/tests/functional/*.py
.include "../../lang/python/application.mk"

EGDIR=		${PREFIX}/share/examples/trac

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	cd ${WRKSRC}/contrib && pax -rwppm -s ',./rpm/.*$$,,' -s ',./rpm$$,,' \
		. ${DESTDIR}${EGDIR}

.include "options.mk"

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
