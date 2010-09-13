# $NetBSD: Makefile,v 1.3 2010/09/13 14:12:15 taca Exp $

DISTNAME=	merb-gen-1.1.3
CATEGORIES=	www

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb application and plugin generator scripts
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=0.9.2:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-rubigen>=1.2.4:../../devel/rubigen
DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=1.1.3:../../devel/ruby-rspec

CONFLICTS+=	ruby[1-9][0-9]-merb-gen-[0-9] merb-gen-[0-9]

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
