# $NetBSD: Makefile,v 1.9 2006/03/04 21:30:49 jlam Exp $
#

DISTNAME=	XML-LibXML-XPathContext-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5xlx
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl interface to libxml2's xmlXPathContext

DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML

PERL5_PACKLIST=	auto/XML/LibXML/XPathContext/.packlist

.include "../../lang/perl5/module.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
