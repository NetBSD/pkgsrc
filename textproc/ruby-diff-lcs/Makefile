# $NetBSD: Makefile,v 1.20 2017/04/22 18:27:05 taca Exp $

DISTNAME=	diff-lcs-1.3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://diff-lcs.rubyforge.org/
COMMENT=	Diff library for Ruby
LICENSE=	gnu-gpl-v2 OR artistic OR ruby-license

RUBYGEM_OPTIONS+=	--format-executable

RUBY_VERSIONS_ACCEPTED= 23 22 21

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
