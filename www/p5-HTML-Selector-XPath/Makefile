# $NetBSD: Makefile,v 1.29 2023/10/22 10:10:44 wen Exp $

DISTNAME=	HTML-Selector-XPath-0.28
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTML-Selector-XPath
COMMENT=	Perl 5 CSS Selector to XPath compiler
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Test-Base-[0-9]*:../../devel/p5-Test-Base

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/HTML/Selector/XPath/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
