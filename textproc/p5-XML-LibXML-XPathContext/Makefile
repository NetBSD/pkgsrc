# $NetBSD: Makefile,v 1.2 2004/10/03 00:18:20 tv Exp $
#

DISTNAME=	XML-LibXML-XPathContext-0.06
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5xlx
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl interface to libxml2's xmlXPathContext

DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML

USE_BUILDLINK3= yes
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/LibXML/XPathContext/.packlist

.include "../../lang/perl5/module.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
