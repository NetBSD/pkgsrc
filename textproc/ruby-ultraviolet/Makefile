# $NetBSD: Makefile,v 1.6 2017/09/04 18:01:02 wiz Exp $

DISTNAME=	ultraviolet-1.0.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://ultraviolet.rubyforge.org/
COMMENT=	Syntax highlighting engine based on Textpow
LICENSE=	mit

DEPENDS+=       ${RUBY_PKGPREFIX}-textpow>=1.3.0:../../textproc/ruby-textpow

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
