# $NetBSD: Makefile,v 1.16 2019/08/11 13:23:57 wiz Exp $

DISTNAME=	XML-TreeBuilder-5.4
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-TreeBuilder
COMMENT=	Perl 5 parser that builds a tree of XML::Element objects
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/XML/TreeBuilder/.packlist

DEPENDS+=	p5-HTML-Tree>=4.1:../../www/p5-HTML-Tree
DEPENDS+=	p5-HTML-Tagset>=3.02:../../www/p5-HTML-Tagset
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser
DEPENDS+=	p5-XML-Catalog-[0-9]*:../../textproc/p5-XML-Catalog

PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
