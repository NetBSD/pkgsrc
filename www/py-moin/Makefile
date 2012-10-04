# $NetBSD: Makefile,v 1.21 2012/10/04 00:21:58 cheusov Exp $
#

VER=		1.9.4
DISTNAME=	moin-${VER}
PKGNAME=	${PYPKGPREFIX}-moin-${VER}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://static.moinmo.in/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://moinmo.in/
COMMENT=	MoinMoin, a Python clone of WikiWiki
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none

REPLACE_PYTHON=	MoinMoin/i18n/tools/markup15to16.py \
		MoinMoin/i18n/tools/po2wiki.py \
		MoinMoin/i18n/tools/prepend.py \
		MoinMoin/i18n/tools/wiki2po.py \
		wiki/server/moin*

REPLACE_PERL=	MoinMoin/web/static/htdocs/applets/FCKeditor/editor/dialog/fck_spellerpages/spellerpages/server-scripts/spellchecker.pl

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/distutils.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
