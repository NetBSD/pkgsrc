# $NetBSD: Makefile,v 1.21 2022/06/28 11:37:48 wiz Exp $

DISTNAME=	Web-Scraper-0.38
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Web/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Web-Scraper
COMMENT=	Perl 5 Web Scraping Toolkit inspired by Scrapi
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Web/Scraper/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

DEPENDS+=	p5-HTML-Parser-[0-9]*:../../www/p5-HTML-Parser
DEPENDS+=	p5-HTML-Selector-XPath>=0.03:../../www/p5-HTML-Selector-XPath
DEPENDS+=	p5-HTML-Tagset-[0-9]*:../../www/p5-HTML-Tagset
DEPENDS+=	p5-HTML-Tree>=3.23:../../www/p5-HTML-Tree
DEPENDS+=	p5-HTML-TreeBuilder-XPath>=0.08:../../www/p5-HTML-TreeBuilder-XPath
DEPENDS+=	p5-libwww>=5.827:../../www/p5-libwww
DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-XML-XPathEngine>=0.08:../../textproc/p5-XML-XPathEngine
DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
DEPENDS+=	p5-HTML-TreeBuilder-LibXML>=0.04:../../www/p5-HTML-TreeBuilder-LibXML

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
