# $NetBSD: Makefile,v 1.7 2025/11/03 07:26:12 taca Exp $

DISTNAME=	commonmarker-2.5.0
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gjtorikian/commonmarker
COMMENT=	CommonMark parser and renderer written in C, wrapped in Ruby
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-rb_sys>=0.9<1:../../devel/ruby-rb_sys

USE_TOOLS+=	gmake

RUBYGEM_OPTIONS+=	--format-executable

.include "cargo-depends.mk"

# XXX: including "lang/ruby/gem.mk" after "lang/rust/cargo.mk" cause
# ignoring gem-extract target...
#
.include "../../lang/ruby/gem.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
