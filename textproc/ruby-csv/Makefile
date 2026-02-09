# $NetBSD: Makefile,v 1.21 2026/02/09 07:51:35 taca Exp $

DISTNAME=	csv-3.3.5
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/csv/
COMMENT=	CSV Reading and Writing
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

# Ruby 4.0.1 has the same version as bundled gem.
RUBY_VERSIONS_ACCEPTED=	32 33 34

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
