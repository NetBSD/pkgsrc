# $NetBSD: Makefile,v 1.1.1.1 2008/04/04 15:25:06 jlam Exp $

DISTNAME=	merb_stories-0.9.2
PKGNAME=	${DISTNAME:S/_/-/g}
CATEGORIES=	www
MASTER_SITES=	http://rubyforge.org/frs/download.php/34350/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin that provides helpers for using RSpec

DEPENDS+=	merb-core>=0.9.2:../../www/merb-core
DEPENDS+=	${RUBY_PKGPREFIX}-rspec>=1.1.3:../../devel/ruby-rspec

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/bsd.pkg.mk"
