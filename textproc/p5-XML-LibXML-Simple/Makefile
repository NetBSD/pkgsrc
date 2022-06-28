# $NetBSD: Makefile,v 1.25 2022/06/28 11:36:42 wiz Exp $

DISTNAME=	XML-LibXML-Simple-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-LibXML-Simple
COMMENT=	XML::LibXML clone of XML::Simple
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-Slurp-Tiny-[0-9]*:../../devel/p5-File-Slurp-Tiny
DEPENDS+=	p5-XML-LibXML>=1.64:../../textproc/p5-XML-LibXML

# TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Pod>=1.00:../../devel/p5-Test-Pod

EXTRACT_USING=	bsdtar

PERL5_PACKLIST=		auto/XML/LibXML/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
