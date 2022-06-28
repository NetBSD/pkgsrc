# $NetBSD: Makefile,v 1.18 2022/06/28 11:37:26 wiz Exp $

DISTNAME=	HTML-TreeBuilder-XPath-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/HTML-TreeBuilder-XPath
COMMENT=	Perl 5 module adding XPath support to HTML::TreeBuilder
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/HTML/TreeBuilder/XPath/.packlist

DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree
DEPENDS+=	p5-XML-XPathEngine>=0.12:../../textproc/p5-XML-XPathEngine

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
