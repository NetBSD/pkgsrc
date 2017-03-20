# $NetBSD: Makefile,v 1.19 2017/03/20 15:26:04 taca Exp $

DISTNAME=	diff-lcs-1.3
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://diff-lcs.rubyforge.org/
COMMENT=	Diff library for Ruby
LICENSE=	gnu-gpl-v2 OR artistic OR ruby-license

RUBYGEM_OPTIONS+=	--format-executable

RUBY_VERSIONS_ACCEPTED= 18 21 22 23

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
