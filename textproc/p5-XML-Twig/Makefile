# $NetBSD: Makefile,v 1.40 2019/07/01 21:35:55 nia Exp $

DISTNAME=	XML-Twig-3.52
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Twig
COMMENT=	Efficient XML document interface
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-XML-Parser>=2.23:../../textproc/p5-XML-Parser

# The modules listed below are required for testing purposes only
# they are not required for building the package
#DEPENDS+=	p5-HTML-Tree-[0-9]*:../../www/p5-HTML-Tree
#DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
#DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
#DEPENDS+=	p5-Test-Pod-Coverage>=1.0:../../devel/p5-Test-Pod-Coverage
#DEPENDS+=	p5-Text-Iconv-[0-9]*:../../converters/p5-Text-Iconv
#DEPENDS+=	p5-Tie-IxHash-[0-9]*:../../devel/p5-Tie-IxHash
#DEPENDS+=	p5-Unicode-Map8-[0-9]*:../../converters/p5-Unicode-Map8
#DEPENDS+=	p5-Unicode-String-[0-9]*:../../converters/p5-Unicode-String
#DEPENDS+=	p5-XML-Filter-BufferText-[0-9]*:../../textproc/p5-XML-Filter-BufferText
#DEPENDS+=	p5-XML-Handler-YAWriter-[0-9]*:../../textproc/p5-XML-Handler-YAWriter
#DEPENDS+=	p5-XML-SAX-Writer-[0-9]*:../../textproc/p5-XML-SAX-Writer
#DEPENDS+=	p5-XML-Simple-[0-9]*:../../textproc/p5-XML-Simple
#DEPENDS+=	p5-XML-XPath-[0-9]*:../../textproc/p5-XML-XPath
#DEPENDS+=	p5-YAML-[0-9]*:../../textproc/p5-YAML
#DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=		auto/XML/Twig/.packlist
MAKE_ENV+=		PERL_MM_USE_DEFAULT=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
