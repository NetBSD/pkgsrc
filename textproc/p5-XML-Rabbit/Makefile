# $NetBSD: Makefile,v 1.17 2017/06/05 14:24:58 ryoon Exp $

DISTNAME=	XML-Rabbit-0.4.1
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Rabbit/
COMMENT=	Perl 5 module to consume XML with Moose and xpath queries
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/XML/Rabbit/.packlist

REPLACE_PERL+=	bin/*

DEPENDS+=	p5-Data-Visitor-[0-9]*:../../devel/p5-Data-Visitor
DEPENDS+=	p5-Moose>=0.89:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Role-Parameterized-[0-9]*:../../devel/p5-MooseX-Role-Parameterized
DEPENDS+=	p5-Perl6-Junction-[0-9]*:../../devel/p5-Perl6-Junction
DEPENDS+=	p5-XML-LibXML>=1.70:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-namespace-autoclean-[0-9]*:../../devel/p5-namespace-autoclean

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
