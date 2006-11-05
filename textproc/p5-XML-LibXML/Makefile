# $NetBSD: Makefile,v 1.23 2006/11/05 14:05:07 seb Exp $
#

DISTNAME=	XML-LibXML-1.61003
PKGNAME=	p5-XML-LibXML-1.61.003
SVR4_PKGNAME=	p5xlx
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~phish/XML-LibXML/
COMMENT=	Perl interface to the libxml2 library

DEPENDS+=	p5-XML-SAX>=0.11:../../textproc/p5-XML-SAX
DEPENDS+=	p5-XML-NamespaceSupport>=1.07:../../textproc/p5-XML-NamespaceSupport
DEPENDS+=	p5-XML-LibXML-Common-[0-9]*:../../textproc/p5-XML-LibXML-Common

# since version 1.61 the XML::LibXML Perl module
# includes XML::LibXML::XPathContext module
CONFLICTS+=	p5-XML-LibXML-XPathContext-[0-9]*

WRKSRC=		${WRKDIR}/XML-LibXML-1.61

PERL5_PACKLIST=		auto/XML/LibXML/.packlist

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
