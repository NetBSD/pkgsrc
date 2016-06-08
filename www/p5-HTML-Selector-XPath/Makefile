# $NetBSD: Makefile,v 1.14 2016/06/08 19:25:04 wiz Exp $

DISTNAME=	HTML-Selector-XPath-0.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
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
