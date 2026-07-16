# $NetBSD: Makefile,v 1.109 2026/07/16 19:05:25 wiz Exp $

DISTNAME=	XML-LibXML-2.0213
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TO/TODDR/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-LibXML
COMMENT=	Perl interface to the libxml2 library
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Alien-Build-[0-9]*:../../devel/p5-Alien-Build
TOOL_DEPENDS+=	p5-Alien-Libxml2-[0-9]*:../../textproc/p5-Alien-Libxml2
DEPENDS+=	p5-XML-SAX>=0.11:../../textproc/p5-XML-SAX
DEPENDS+=	p5-XML-NamespaceSupport>=1.07:../../textproc/p5-XML-NamespaceSupport

SUPERSEDES=	p5-XML-LibXML-Common<=0.13nb7
CONFLICTS+=	p5-XML-LibXML-Common-[0-9]*

# since version 1.61 the XML::LibXML Perl module
# includes XML::LibXML::XPathContext module
CONFLICTS+=	p5-XML-LibXML-XPathContext-[0-9]*

# as of 2.0210
# Failed 8/78 test programs. 11/2612 subtests failed.

PERL5_PACKLIST=		auto/XML/LibXML/.packlist

FILES_SUBST+=		PERL5_INSTALLVENDORLIB=${PERL5_INSTALLVENDORLIB:Q}

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
