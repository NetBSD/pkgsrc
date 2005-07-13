# $NetBSD: Makefile,v 1.18 2005/07/13 18:01:43 jlam Exp $
#

DISTNAME=	XML-LibXML-1.58
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xlx
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~phish/XML-LibXML/
COMMENT=	Perl interface to the libxml2 library

DEPENDS+=	p5-XML-SAX>=0.03:../../textproc/p5-XML-SAX
DEPENDS+=	p5-XML-Checker-[0-9]*:../../textproc/p5-XML-Checker
DEPENDS+=	p5-XML-LibXML-Common-[0-9]*:../../textproc/p5-XML-LibXML-Common

PERL5_PACKLIST=		auto/XML/LibXML/.packlist

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
