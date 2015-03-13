# $NetBSD: Makefile,v 1.6 2015/03/13 16:24:59 taca Exp $

DISTNAME=	textpow-1.4.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/grosser/textpow/
COMMENT=	Library to parse and process Textmate bundles
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-plist>=3.0.1:../../textproc/ruby-plist

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
