# $NetBSD: Makefile,v 1.4 2025/08/12 03:53:58 ryoon Exp $

DISTNAME=	strings-0.2.1
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/piotrmurach/strings
COMMENT=	Set of useful functions for transforming strings
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-strings-ansi>=0.2<1:../../textproc/ruby-strings-ansi
DEPENDS+=	${RUBY_PKGPREFIX}-unicode_utils>=1.4<2:../../textproc/ruby-unicode_utils
DEPENDS+=	${RUBY_PKGPREFIX}-unicode-display_width>=1.5:../../textproc/ruby-unicode-display_width

USE_LANGUAGES=	# none

OVERRIDE_GEMSPEC+=	unicode-display_width>=3.1.0

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
