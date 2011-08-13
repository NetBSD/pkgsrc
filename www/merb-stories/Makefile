# $NetBSD: Makefile,v 1.4 2011/08/13 00:22:00 taca Exp $

DISTNAME=	merb_stories-0.9.13
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/_/-/g}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://rubyforge.org/frs/download.php/46246/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.merbivore.com/
COMMENT=	Merb plugin that provides helpers for using RSpec

DEPENDS+=	${RUBY_PKGPREFIX}-merb>=0.4.0:../../www/merb

CONFLICTS+=	merb-stories-[0-9]*

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
