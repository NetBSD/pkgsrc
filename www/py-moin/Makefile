# $NetBSD: Makefile,v 1.17 2012/01/27 05:52:40 obache Exp $
#

VER=		1.9.3
DISTNAME=	moin-${VER}
PKGNAME=	${PYPKGPREFIX}-moin-${VER}
PKGREVISION=	2
CATEGORIES=	www python
MASTER_SITES=	http://static.moinmo.in/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://moinmo.in/
COMMENT=	MoinMoin, a Python clone of WikiWiki
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

#Only for Python 2.4, which isn't recommended anyway
#DEPENDS+=	${PYPKGPREFIX}-xml-[0-9]*:../../textproc/py-xml

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27 26 25 24

REPLACE_PYTHON=	MoinMoin/i18n/tools/markup15to16.py \
		MoinMoin/i18n/tools/po2wiki.py \
		MoinMoin/i18n/tools/prepend.py \
		MoinMoin/i18n/tools/wiki2po.py \
		wiki/server/moin*

REPLACE_PERL=	MoinMoin/web/static/htdocs/applets/FCKeditor/editor/dialog/fck_spellerpages/spellerpages/server-scripts/spellchecker.pl

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
