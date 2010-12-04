# $NetBSD: Makefile,v 1.2 2010/12/04 04:38:20 taca Exp $

DISTNAME=	treetop-1.4.9
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.rubyonrails.org/
COMMENT=	Ruby-based text parsing and interpretation DSL
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-polyglot>=0.3.1:../../devel/ruby-polyglot

CONFLICTS=	ruby[1-9][0-9]-treetop-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
