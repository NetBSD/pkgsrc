# $NetBSD: Makefile,v 1.12 2018/08/22 09:47:40 wiz Exp $

DISTNAME=	HTML-TreeBuilder-XPath-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-TreeBuilder-XPath/
COMMENT=	Perl 5 module adding XPath support to HTML::TreeBuilder
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/HTML/TreeBuilder/XPath/.packlist

DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree
DEPENDS+=	p5-XML-XPathEngine>=0.12:../../textproc/p5-XML-XPathEngine

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
