# $NetBSD: Makefile,v 1.10 2006/01/24 07:32:37 wiz Exp $
#

DISTNAME=	XML-LibXSLT-1.57
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5xlt
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	adam@migus.org
HOMEPAGE=	http://search.cpan.org/~phish/XML-LibXML/
COMMENT=	Perl interface to the libxslt library

DEPENDS+=	p5-XML-LibXML>=1.49:../../textproc/p5-XML-LibXML

PERL5_PACKLIST=	auto/XML/LibXSLT/.packlist

.include "../../textproc/libxslt/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
