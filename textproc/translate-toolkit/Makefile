# $NetBSD: Makefile,v 1.1 2018/03/11 15:42:31 rillig Exp $

DISTNAME=	translate-toolkit-2.2.5
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=translate/}
GITHUB_PROJECT=	translate
GITHUB_RELEASE=	2.2.5

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	https://github.com/translate/translate/
COMMENT=	Tools for working with translation files
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-six>=0:../../lang/py-six
DEPENDS+=	${PYPKGPREFIX}-diff-match-patch-20121119{,nb*}:../../textproc/py-diff-match-patch
USE_LANGUAGES=	# none
USE_TOOLS+=	bash:run
REPLACE_BASH=	* */* */*/*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
