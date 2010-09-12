# $NetBSD: Makefile,v 1.2 2010/09/12 02:52:32 taca Exp $

DISTNAME=	merb_stories-0.9.13
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	www
MASTER_SITES=	http://rubyforge.org/frs/download.php/46246/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin that provides helpers for using RSpec

DEPENDS+=	${RUBY_PKGPREFIX}-merb-core>=0.9.2:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=1.1.3:../../devel/ruby-rspec

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
