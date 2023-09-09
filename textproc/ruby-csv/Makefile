# $NetBSD: Makefile,v 1.11 2023/09/09 13:52:57 taca Exp $

DISTNAME=	csv-3.2.7
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/csv/
COMMENT=	CSV Reading and Writing
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

# This package is for redmine50 on Ruby 3.0.
# Ruby 3.2 has the same version as default gem.
RUBY_VERSIONS_ACCEPTED=	31

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
