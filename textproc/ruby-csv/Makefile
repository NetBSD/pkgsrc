# $NetBSD: Makefile,v 1.4 2021/06/10 14:25:42 taca Exp $

DISTNAME=	csv-3.1.9
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/csv/
COMMENT=	CSV Reading and Writing
LICENSE=	2-clause-bsd

# Ruby 3.0 contain the same version of rexml.
RUBY_VERSIONS_ACCEPTED=	26 27

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
