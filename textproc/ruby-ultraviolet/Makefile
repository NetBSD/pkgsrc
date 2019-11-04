# $NetBSD: Makefile,v 1.7 2019/11/04 21:43:47 rillig Exp $

DISTNAME=	ultraviolet-1.0.1
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://ultraviolet.rubyforge.org/
COMMENT=	Syntax highlighting engine based on Textpow
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-textpow>=1.3.0:../../textproc/ruby-textpow

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
