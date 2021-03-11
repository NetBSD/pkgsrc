# $NetBSD: Makefile,v 1.3 2021/03/11 15:26:15 taca Exp $

DISTNAME=	strings-0.2.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/piotrmurach/strings
COMMENT=	Set of useful functions for transforming strings
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-strings-ansi>=0.2<1:../../textproc/ruby-strings-ansi
DEPENDS+=	${RUBY_PKGPREFIX}-unicode_utils>=1.4<2:../../textproc/ruby-unicode_utils
DEPENDS+=	${RUBY_PKGPREFIX}-unicode-display_width>=1.5:../../textproc/ruby-unicode-display_width

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
