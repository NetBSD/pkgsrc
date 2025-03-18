# $NetBSD: Makefile,v 1.18 2025/03/18 13:48:00 taca Exp $

DISTNAME=	csv-3.3.2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/csv/
COMMENT=	CSV Reading and Writing
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

# Ruby 3.4.1 has csv 3.3.2 gem.
RUBY_VERSIONS_ACCEPTED=	31 32 33

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
