# $NetBSD: Makefile,v 1.23 2024/11/05 15:02:22 taca Exp $

DISTNAME=	rexml-3.3.9
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/rexml
COMMENT=	XML toolkit for Ruby
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# empty

# Ruby 3.2.6 has the same version as bundled gems.
RUBY_VERSIONS_ACCEPTED=	31 33

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
