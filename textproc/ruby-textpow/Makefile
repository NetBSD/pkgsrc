# $NetBSD: Makefile,v 1.1.1.1 2008/08/22 15:41:23 ahoka Exp $

DISTNAME=	textpow-0.10.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://textpow.rubyforge.org/
COMMENT=	Library to parse and process Textmate bundles

GEM_BUILD=	gemspec

DEPENDS+=	${RUBY_PKGPREFIX}-oniguruma>=1.1.0:../../textproc/ruby-oniguruma
DEPENDS+=	${RUBY_PKGPREFIX}-plist>=3.0.0:../../textproc/ruby-plist

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
