# $NetBSD: Makefile,v 1.4 2011/08/13 00:18:29 taca Exp $

DISTNAME=	merb-gen-1.1.3
PKGREVISION=	1
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb application and plugin generator scripts
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=1.1.3<1.2:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-templater>=1.0.0:../../devel/ruby-templater

CONFLICTS+=	ruby[1-9][0-9]-merb-gen-[0-9] merb-gen-[0-9]

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
