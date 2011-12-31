# $NetBSD: Makefile,v 1.4 2011/12/31 16:03:21 taca Exp $

DISTNAME=	merb-core-1.1.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb core classes and framework
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-extlib>=0.9.13:../../devel/ruby-extlib
DEPENDS+=	${RUBY_PKGPREFIX}-erubis>=2.6.2:../../www/ruby-erubis
DEPENDS+=	${RUBY_PKGPREFIX}-rack>=0:../../www/ruby-rack
DEPENDS+=	${RUBY_PKGPREFIX}-mime-types>=1.16:../../mail/ruby-mime-types
DEPENDS+=	${RUBY_PKGPREFIX}-bundler>=0:../../misc/ruby-bundler

CONFLICTS+=	ruby[1-9][0-9]-merb-core-[0-9]* merb-core-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
