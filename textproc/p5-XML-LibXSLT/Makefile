# $NetBSD: Makefile,v 1.12 2006/11/05 19:56:36 seb Exp $
#

DISTNAME=	XML-LibXSLT-1.61
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5xlt
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	adam@migus.org
HOMEPAGE=	http://search.cpan.org/dist/XML-LibXSLT/
COMMENT=	Perl interface to the libxslt library

DEPENDS+=	p5-XML-LibXML>=1.60:../../textproc/p5-XML-LibXML

PERL5_PACKLIST=	auto/XML/LibXSLT/.packlist

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
