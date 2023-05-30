# $NetBSD: Makefile,v 1.10 2023/05/30 15:34:58 taca Exp $

DISTNAME=	csv-3.2.6
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/csv/
COMMENT=	CSV Reading and Writing
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

# This package is for redmine50 on Ruby 3.0.
# Ruby 3.2 has the same version as default gem.
RUBY_VERSIONS_ACCEPTED=	30 31

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
