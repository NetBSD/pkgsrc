# $NetBSD: Makefile,v 1.4 2004/10/03 00:18:20 tv Exp $
#

DISTNAME=	XML-LibXSLT-1.53
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5xlt
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	adam@migus.org
HOMEPAGE=	http://search.cpan.org/~phish/XML-LibXML/
COMMENT=	Perl interface to the libxslt library

DEPENDS+=	p5-XML-LibXML>=1.49:../../textproc/p5-XML-LibXML

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/LibXSLT/.packlist

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
