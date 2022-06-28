# $NetBSD: Makefile,v 1.35 2022/06/28 11:36:41 wiz Exp $
#

DISTNAME=	XML-Grove-0.46alpha
PKGNAME=	p5-${DISTNAME:S/alpha/.0.1/}
PKGREVISION=	18
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	explorer@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/XML-Grove
COMMENT=	Perl 5 module providing simple objects for parsed XML documents
LICENSE=	artistic

DEPENDS+=	p5-libxml>=0.0.7:../../textproc/p5-libxml

PERL5_PACKLIST=		auto/XML/Grove/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
