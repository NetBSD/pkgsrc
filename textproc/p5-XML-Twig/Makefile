# $NetBSD: Makefile,v 1.10 2006/01/24 07:32:38 wiz Exp $
#

DISTNAME=	XML-Twig-3.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5xtw
CATEGORIES=	textproc perl5
MASTER_SITES=	http://www.xmltwig.com/xmltwig/ \
		${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.xmltwig.com/
COMMENT=	Efficient XML document interface

DEPENDS+=	p5-WeakRef>=0.01:../../devel/p5-WeakRef
DEPENDS+=	p5-XML-Parser>=2.23:../../textproc/p5-XML-Parser
DEPENDS+=	p5-File-Temp>=0.12:../../devel/p5-File-Temp

# These are only needed for the test target
#DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
#DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
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

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/XML/Twig/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
