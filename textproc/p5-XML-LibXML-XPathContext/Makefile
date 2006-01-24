# $NetBSD: Makefile,v 1.7 2006/01/24 07:32:37 wiz Exp $
#

DISTNAME=	XML-LibXML-XPathContext-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5xlx
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl interface to libxml2's xmlXPathContext

DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML

PERL5_PACKLIST=	auto/XML/LibXML/XPathContext/.packlist

.include "../../lang/perl5/module.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
