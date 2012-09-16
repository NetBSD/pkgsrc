# $NetBSD: Makefile,v 1.3 2012/09/16 11:35:39 taca Exp $

DISTNAME=	textpow-1.3.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://textpow.rubyforge.org/
COMMENT=	Library to parse and process Textmate bundles
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-plist>=3.0.0:../../textproc/ruby-plist

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
