# $NetBSD: Makefile,v 1.2 2010/09/12 02:32:52 taca Exp $

DISTNAME=	merb-action-args-1.1.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin to map query parameters to controller method arguments
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=1.1.3:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-ruby2ruby>=1.1.9:../../devel/ruby2ruby
DEPENDS+=	${RUBY_PKGPREFIX}-parsetree>=2.2.1:../../devel/ruby-parsetree

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
