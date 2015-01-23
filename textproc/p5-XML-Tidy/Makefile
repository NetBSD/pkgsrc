# $NetBSD: Makefile,v 1.11 2015/01/23 06:50:07 obache Exp $
#

DISTNAME=	XML-Tidy-1.12.B55J2qn
PKGNAME=	p5-${DISTNAME:C:\.[^.]*$::}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Tidy/
COMMENT=	Tidy indenting of XML documents
LICENSE=	gnu-gpl-v3

DEPENDS+=    	p5-XML-XPath-[0-9]*:../../textproc/p5-XML-XPath
DEPENDS+=    	p5-Math-BaseCnv-[0-9]*:../../math/p5-Math-BaseCnv

PERL5_PACKLIST=		auto/XML/Tidy/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
