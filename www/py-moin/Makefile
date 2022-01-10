# $NetBSD: Makefile,v 1.45 2022/01/10 18:40:33 wiz Exp $

VER=		1.9.11
DISTNAME=	moin-${VER}
PKGNAME=	${PYPKGPREFIX}-moin-${VER}
PKGREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://static.moinmo.in/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://moinmo.in/
COMMENT=	MoinMoin, a Python clone of WikiWiki
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=	# none

PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 1.9.10

REPLACE_PYTHON=	jabberbot/bot.py \
		MoinMoin/version.py \
		MoinMoin/filter/EXIF.py \
		MoinMoin/i18n/msgfmt.py \
		MoinMoin/i18n/tools/*.py \
		MoinMoin/script/moin.py \
		MoinMoin/script/old/*.py \
		MoinMoin/script/old/xmlrpc-tools/*.py \
		MoinMoin/script/migration/1050800.py \
		MoinMoin/script/migration/1059997.py \
		MoinMoin/script/migration/1059998.py \
		MoinMoin/script/migration/1059999.py \
		MoinMoin/script/migration/1089999.py \
		MoinMoin/script/old/migration/*.py \
		MoinMoin/support/xappy/*.py \
		MoinMoin/web/static/htdocs/applets/FCKeditor/editor/filemanager/connectors/py/*.py \
		wiki/server/moin* \
		wiki/server/test.wsgi

REPLACE_PERL=	MoinMoin/web/static/htdocs/applets/FCKeditor/editor/dialog/fck_spellerpages/spellerpages/server-scripts/spellchecker.pl
REPLACE_PERL+=	MoinMoin/web/static/htdocs/applets/FCKeditor/editor/filemanager/connectors/perl/connector.cgi
REPLACE_PERL+=	MoinMoin/web/static/htdocs/applets/FCKeditor/editor/filemanager/connectors/perl/upload.cgi

PYTHON_SELF_CONFLICT=	yes

.include "../../lang/python/egg.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
