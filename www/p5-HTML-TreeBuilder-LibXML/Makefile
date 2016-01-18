# $NetBSD: Makefile,v 1.15 2016/01/18 11:57:07 mef Exp $

DISTNAME=	HTML-TreeBuilder-LibXML-0.25
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=HTML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/HTML-TreeBuilder-LibXML/
COMMENT=	Perl 5 HTML::TreeBuilder and XPath compatible interface with libxml
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/HTML/TreeBuilder/LibXML/.packlist

PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	p5-HTML-TreeBuilder-XPath>=0.14:../../www/p5-HTML-TreeBuilder-XPath
DEPENDS+=	p5-XML-LibXML>=1.70:../../textproc/p5-XML-LibXML

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
