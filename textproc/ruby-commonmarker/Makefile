# $NetBSD: Makefile,v 1.5 2023/04/30 13:31:32 taca Exp $

DISTNAME=	commonmarker-0.23.9
CATEGORIES=	textproc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/gjtorikian/commonmarker
COMMENT=	CommonMark parser and renderer written in C, wrapped in Ruby
LICENSE=	mit

RUBYGEM_OPTIONS+=	--format-executable

.include "../../textproc/cmark/buildlink3.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
