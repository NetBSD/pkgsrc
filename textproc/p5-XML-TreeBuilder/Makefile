# $NetBSD: Makefile,v 1.5 2012/10/25 06:56:41 asau Exp $

DISTNAME=	XML-TreeBuilder-3.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-TreeBuilder/
COMMENT=	Perl 5 parser that builds a tree of XML::Element objects
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
# The '-' below is not a typo!
PERL5_PACKLIST= auto/XML-TreeBuilder/.packlist

DEPENDS+=	p5-HTML-Tree>=3.08:../../www/p5-HTML-Tree
DEPENDS+=	p5-HTML-Tagset>=3.02:../../www/p5-HTML-Tagset
DEPENDS+=	p5-XML-Parser-[0-9]*:../../textproc/p5-XML-Parser

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
