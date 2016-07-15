# $NetBSD: Makefile,v 1.15 2016/07/15 02:50:08 wen Exp $

DISTNAME=	HTML-Selector-XPath-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-Selector-XPath/
COMMENT=	Perl 5 CSS Selector to XPath compiler
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+= p5-Test-Base-[0-9]*:../../devel/p5-Test-Base

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/HTML/Selector/XPath/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
