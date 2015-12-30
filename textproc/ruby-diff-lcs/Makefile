# $NetBSD: Makefile,v 1.16 2015/12/30 15:11:40 taca Exp $

DISTNAME=	diff-lcs-1.2.5
PKGREVISION=	2
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://diff-lcs.rubyforge.org/
COMMENT=	Diff library for Ruby
LICENSE=	gnu-gpl-v2 OR artistic OR ruby-license

RUBYGEM_OPTIONS+=	--format-executable

RUBY_VERSION_SUPPORTED= 18 200 21 22 23

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
