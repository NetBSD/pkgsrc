# $NetBSD: Makefile,v 1.13 2010/03/20 21:12:03 pettai Exp $
#

VER=		1.9.2
DISTNAME=	moin-${VER}
PKGNAME=	${PYPKGPREFIX}-moin-${VER}
CATEGORIES=	www python
MASTER_SITES=	http://static.moinmo.in/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://moinmo.in/
COMMENT=	MoinMoin, a Python clone of WikiWiki
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

#Only for Python 2.4, which isn't recommended anyway
#DEPENDS+=	${PYPKGPREFIX}-xml-[0-9]*:../../textproc/py-xml

PYTHON_VERSIONS_ACCEPTED=	26 25 24
PYDISTUTILSPKG=	# empty

REPLACE_INTERPRETER+=	env_python
REPLACE.env_python.old=	/usr/bin/env python
REPLACE.env_python.new= ${PYTHONBIN}
REPLACE_FILES.env_python=	wiki/server/moin*

REPLACE_PYTHON=	MoinMoin/i18n/tools/markup15to16.py \
		MoinMoin/i18n/tools/po2wiki.py \
		MoinMoin/i18n/tools/prepend.py \
		MoinMoin/i18n/tools/wiki2po.py \
		wiki/server/moin.fcgi

REPLACE_PERL=	MoinMoin/web/static/htdocs/applets/FCKeditor/editor/dialog/fck_spellerpages/spellerpages/server-scripts/spellchecker.pl

.include "../../devel/zlib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
