# $NetBSD: Makefile,v 1.14 2004/10/03 00:18:20 tv Exp $
#

DISTNAME=	XML-LibXML-1.57
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5xlx
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~phish/XML-LibXML/
COMMENT=	Perl interface to the libxml2 library

DEPENDS+=	p5-XML-SAX>=0.03:../../textproc/p5-XML-SAX
DEPENDS+=	p5-XML-Checker-[0-9]*:../../textproc/p5-XML-Checker
DEPENDS+=	p5-XML-LibXML-Common-[0-9]*:../../textproc/p5-XML-LibXML-Common

USE_BUILDLINK3=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/LibXML/.packlist

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
