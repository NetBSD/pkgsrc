# $NetBSD: Makefile,v 1.4 2012/09/16 11:32:01 taca Exp $

DISTNAME=	ultraviolet-1.0.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://ultraviolet.rubyforge.org/
COMMENT=	Syntax highlighting engine based on Textpow
LICENSE=	mit

DEPENDS+=       ${RUBY_PKGPREFIX}-textpow>=1.3.0:../../textproc/ruby-textpow

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
