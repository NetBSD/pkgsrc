# $NetBSD: Makefile,v 1.4 2023/02/04 13:29:25 taca Exp $

DISTNAME=	commonmarker-0.23.8
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gjtorikian/commonmarker
COMMENT=	CommonMark parser and renderer written in C, wrapped in Ruby
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable

.include "../../textproc/cmark/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
