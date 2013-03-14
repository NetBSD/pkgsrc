# $NetBSD: Makefile,v 1.4 2013/03/14 16:13:52 taca Exp $

DISTNAME=	textpow-1.3.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/grosser/textpow/
COMMENT=	Library to parse and process Textmate bundles
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-plist>=3.0.0:../../textproc/ruby-plist

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
