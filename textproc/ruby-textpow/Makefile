# $NetBSD: Makefile,v 1.7 2015/12/12 04:14:03 taca Exp $

DISTNAME=	textpow-1.4.0
PKGREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/grosser/textpow/
COMMENT=	Library to parse and process Textmate bundles
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-plist>=3.0.1:../../textproc/ruby-plist

RUBYGEM_OPTIONS+=	--format-executable

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
