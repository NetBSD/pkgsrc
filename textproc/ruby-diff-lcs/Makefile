# $NetBSD: Makefile,v 1.15 2015/12/12 04:12:18 taca Exp $

DISTNAME=	diff-lcs-1.2.5
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://diff-lcs.rubyforge.org/
COMMENT=	Diff library for Ruby
LICENSE=	gnu-gpl-v2 OR artistic OR ruby-license

RUBYGEM_OPTIONS+=	--format-executable

RUBY_VERSION_SUPPORTED= 18 200 21 22

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
