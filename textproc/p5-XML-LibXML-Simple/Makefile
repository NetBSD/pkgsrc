# $NetBSD: Makefile,v 1.8 2012/10/25 06:56:37 asau Exp $
#

DISTNAME=	XML-LibXML-Simple-0.91
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-LibXML-Simple/
COMMENT=	XML::LibXML clone of XML::Simple
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Pod>=1.00:../../devel/p5-Test-Pod

DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=	p5-XML-LibXML>=1.64:../../textproc/p5-XML-LibXML

PERL5_PACKLIST=		auto/XML/LibXML/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
